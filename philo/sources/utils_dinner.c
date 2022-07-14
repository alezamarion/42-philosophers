/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_dinner.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 02:36:39 by azamario          #+#    #+#             */
/*   Updated: 2022/07/14 14:05:08 by azamario         ###   ########.fr       */
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

void	*died(void *param)
{
	int		i;
	t_data	*data;

	data = param;
	i = -1;
	while (++i < data->number_of_philos)
	{
		pthread_mutex_lock(&data->meal);
		if (is_a_death_philo(data, i))
			return (NULL);
		if (data->philo[i].had_dinner == data->to_dinner
			&& data->to_dinner > 0 && data->philo[i].eating)
		{
			data->ate_dinner++;
			data->philo[i].eating = 0;
		}
		pthread_mutex_unlock(&data->meal);
		if (all_philo_satisfied(data))
			return (NULL);
		if (i + 1 == data->number_of_philos)
			i = -1;
		usleep (1000);
	}
	return (NULL);
}

void	*one_philo(t_philo *philo)
{
	pthread_mutex_lock(&philo->struct_data->forks[philo->left_fork]);
	pthread_mutex_lock(&philo->struct_data->meal);
	philo->last_dinner = get_time();
	pthread_mutex_unlock(&philo->struct_data->meal);
	print_status(get_time(), philo, "has taken a fork 🍴");
	pthread_mutex_unlock(&philo->struct_data->forks[philo->left_fork]);
	print_status(get_time(), philo, "DIED ☠️");
	pthread_mutex_lock(&philo->struct_data->m_checker);
	philo->struct_data->checker = 1;
	pthread_mutex_unlock(&philo->struct_data->m_checker);
	return (NULL);
}

/*
	cria lock para garfos, pega tempo atual e passa para last_dinner
	pausa para executar que philo está comendo (usleep), desbloqueia os garfos
	quando a refeição acaba
*/
void	eat(t_philo *philo)
{
	mutex_lock_fork(philo);
	pthread_mutex_lock(&philo->struct_data->meal);
	philo->eating = 1;
	philo->last_dinner = get_time();
	pthread_mutex_unlock(&philo->struct_data->meal);
	print_status(get_time(), philo, "has taken a fork 🍴");
	print_status(get_time(), philo, "has taken a fork 🍴");
	print_status(get_time(), philo, "is eating 🍔");
	usleep(philo->struct_data->time_to_eat);
	pthread_mutex_lock(&philo->struct_data->meal);
	philo->had_dinner++;
	pthread_mutex_unlock(&philo->struct_data->meal);
	mutex_unlock_fork(philo);
}

long int	get_time(void)
{
	struct timeval	tv;
	long int		milliseconds;

	gettimeofday(&tv, NULL);
	milliseconds = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	return (milliseconds);
}
