/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_dinner.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 02:36:39 by azamario          #+#    #+#             */
/*   Updated: 2022/07/12 21:37:28 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
	verifica se morreu e se comeu o que deveria
	while para execução de cada philo
	get_time(): tem que terminar de comer antes da hora da morte
	depois verifica se o philo já comeu o n de rúmero de refeições que deveria
	depois verifica se todos os philos já comeram o que deveriam
	no último if, reseta o i para passar novamente nos philos
	dá usleep?
	return (NULL)?
*/
void	*died(void *param) // cada thread acessa a sua variável | nao dá data race
{
	int		i;
	t_data	*data;

	data = param;
	i = -1;
	while (++i < data->number_of_philos)
	{
		if (get_time() - data->philo[i].last_dinner > data->time_to_die)
		{
			print_status(get_time(), data->philo + i, "DIED"); //***
			data->checker = 1;
			return (NULL);
		}
		if (data->philo[i].had_dinner == data->to_dinner && data->to_dinner > 0)
			data->ate_dinner++;
		if (data->ate_dinner == data->number_of_philos)
		{
			data->checker = 1;
			return (NULL);
		}
		if (i + 1 == data->number_of_philos)
			i = -1;
		usleep (1000);
	}
	return (NULL);
}

void	*one_philo(t_philo *philo) //colocamos o unlock antes do return
{
	pthread_mutex_lock(&philo->struct_data->forks[philo->right_fork]);
	philo->last_dinner = get_time();
	print_status(get_time(), philo, "has taken a fork");
	usleep(philo->struct_data->time_to_die * 1000); //*****
	print_status(get_time(), philo, "DIED");
	philo->struct_data->checker = 1;
	pthread_mutex_unlock(&philo->struct_data->forks[philo->right_fork]);
	return (NULL);
}

/*
	cria lock para garfos, pega tempo atual e passa para last_dinner
	pausa para executar que philo está comendo (usleep), desbloqueia os garfos
	quando a refeição acaba
*/
void	eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->struct_data->forks[philo->left_fork]);
	pthread_mutex_lock(&philo->struct_data->forks[philo->right_fork]);
	philo->last_dinner = get_time();
	print_status(get_time(), philo, "has taken a fork");
	print_status(get_time(), philo, "has taken a fork");
	print_status(get_time(), philo, "is eating");
	usleep(philo->struct_data->time_to_eat * 1000);
	pthread_mutex_unlock(&philo->struct_data->forks[philo->left_fork]);
	pthread_mutex_unlock(&philo->struct_data->forks[philo->right_fork]);
}

/*
	int gettimeofday(struct timeval *restrict tv, struct timezone *restrict tz);

	The tv argument is a struct timeval (as specified in <sys/time.h>):

    struct timeval
	{
        time_t      tv_sec;     / seconds /
        suseconds_t tv_usec;    / microseconds /
    };

*/

long int	get_time(void)
{
	struct timeval	tv;
	long int		milliseconds;

	gettimeofday(&tv, NULL);
	milliseconds = tv.tv_sec * 1000 + tv.tv_usec / 1000; //fórmula para achar ms
	return (milliseconds);
}
