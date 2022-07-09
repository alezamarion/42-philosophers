/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_dinner.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 02:36:39 by azamario          #+#    #+#             */
/*   Updated: 2022/07/09 04:41:23 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*died(void *param) //verifica se morreu ou se comeu o que deveria
{
	int		i;
	t_data	*data;

	data = param;
	i = -1;
	while (++i < data->number_of_philos) //while para a execução em cada philo
	{
		if (get_time() - data->philo[i].last_dinner > data->time_to_die) //tem que terminar de comer antes da hora da morte
		{
			print_status(get_time(), data->philo, "DIED");
			data->checker = 1;
			return (NULL);
		}
		if (data->philo[i].had_dinner == data->have_to_dinner && data->have_to_dinner > 0) //o philo[i] já comeu o limite de refeições?
			data->ate_dinner++;
		if (data->ate_dinner == data->number_of_philos) //todos os philos já comeram as refeições da linha de comando
		{
			data->checker = 1;
			return (NULL);
		}
		if (i + 1 == data->number_of_philos)		// 	philo[1]	philo[2]	philo[3]
			i = -1;									//	i = 0		i = 1		i = 2		if 3 == 3				 
		usleep (1600);	//*****	look here			// reseta o i para começar novamente
	}
	return (NULL); //7
}



void	*one_philo(t_philo *philo)
{
	pthread_mutex_lock(&philo->struct_data->forks[philo->right_fork]);
	philo->last_dinner = get_time();
	print_status(get_time(), philo, "has taken a fork");
	pthread_mutex_unlock(&philo->struct_data->forks[philo->right_fork]);
	print_status(get_time(), philo, "DIED");
	philo->struct_data->checker = 1;
	return (NULL);	
}

void	eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->struct_data->forks[philo->left_fork]);		//cria lock para os garfos
	pthread_mutex_lock(&philo->struct_data->forks[philo->right_fork]);
	philo->last_dinner = get_time();										//pega tempo atual e passa para variável
	print_status(get_time(), philo, "has taken a fork");
	print_status(get_time(), philo, "has taken a fork");
	print_status(get_time(), philo, "is eating");
	usleep(philo->struct_data->time_to_eat * 1000);							//pausa para executar que o philo está comendo (o tempo da linha de comando)
	pthread_mutex_unlock(&philo->struct_data->forks[philo->left_fork]);
	pthread_mutex_unlock(&philo->struct_data->forks[philo->right_fork]);	//desbloqueia os garfos quando a refeição acaba
}