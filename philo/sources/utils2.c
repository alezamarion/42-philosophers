/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 03:05:46 by azamario          #+#    #+#             */
/*   Updated: 2022/07/14 04:15:11 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	mutex_init(t_data *data)
{
	pthread_mutex_init(&data->meal, NULL);
	pthread_mutex_init(&data->print, NULL);
	pthread_mutex_init(&data->m_checker, NULL);
}

void	mutex_destroy(t_data *data)
{
	int	i;

	i = -1;
	pthread_mutex_destroy(&data->print);
	pthread_mutex_destroy(&data->meal);
	pthread_mutex_destroy(&data->m_checker);
	while (++i < data->number_of_philos)
		pthread_mutex_destroy(&data->forks[i]);
}

void	philo_satisfied(t_data *data)
{
	pthread_mutex_lock(&data->m_checker);
	data->checker = 1;
	pthread_mutex_unlock(&data->m_checker);
}

void	philo_died(t_data *data, int i)
{
	print_status(get_time(), data->philo + i, "DIED");
	pthread_mutex_lock(&data->m_checker);
	data->checker = 1;
	pthread_mutex_unlock(&data->m_checker);
	pthread_mutex_unlock(&data->meal);
}
