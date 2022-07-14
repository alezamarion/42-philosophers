/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 02:33:00 by azamario          #+#    #+#             */
/*   Updated: 2022/07/14 14:07:54 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_status(long int time_now, t_philo *philo, char *status)
{
	pthread_mutex_lock(&philo->struct_data->print);
	pthread_mutex_lock(&philo->struct_data->m_checker);
	if (philo->struct_data->checker != 1)
		printf("time: %6ld | Philo: %3d | Status: %s\n", time_now
			- philo->struct_data->start_dinner, philo->philo_id, status);
	pthread_mutex_unlock(&philo->struct_data->m_checker);
	pthread_mutex_unlock(&philo->struct_data->print);
}

int	is_a_death_philo(t_data *data, int i)
{
	if (get_time() - data->philo[i].last_dinner > data->time_to_die)
	{
		print_status(get_time(), data->philo + i, "DIED ☠️");
		pthread_mutex_lock(&data->m_checker);
		data->checker = 1;
		pthread_mutex_unlock(&data->m_checker);
		pthread_mutex_unlock(&data->meal);
		return (1);
	}
	return (0);
}

int	all_philo_satisfied(t_data *data)
{
	if (data->ate_dinner == data->number_of_philos)
	{
		pthread_mutex_lock(&data->m_checker);
		data->checker = 1;
		pthread_mutex_unlock(&data->m_checker);
		return (1);
	}
	return (0);
}
