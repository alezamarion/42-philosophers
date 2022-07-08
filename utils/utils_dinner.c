/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_dinner.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 02:36:39 by azamario          #+#    #+#             */
/*   Updated: 2022/07/08 18:02:54 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*died(void *param)
{
	int		i;
	t_data	*data;

	data = param;
	i = -1;
	while (++i < data->number_of_philos)
	{
		if (get_time() - data->philo[i].last_meal > data->time_to_die)
		{
			print_status(get_time(), data->philo, "DIED");
			data->checker = 1;
			return (NULL);
		}
		if (data->philo[i].n_meals == data->must_eat && data->must_eat > 0)
			data->ate_meal++;
		if (data->ate_meal == data->number_of_philos)
		{
			data->checker = 1;
			return (NULL);
		}
		if (i + 1 == data->number_of_philos)
			i = -1;
		usleep (1600);
	}
	return (NULL); //7
}



void	*one_philo(t_philo *philo)
{
	pthread_mutex_lock(&philo->struct_data->forks[philo->right_fork]);
	philo->last_meal = get_time();
	print_status(get_time(), philo, "has taken a fork");
	pthread_mutex_unlock(&philo->struct_data->forks[philo->right_fork]);
	print_status(get_time(), philo, "DIED");
	philo->struct_data->checker = 1;
	return (NULL);	
}

void	eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->struct_data->forks[philo->left_fork]);
	pthread_mutex_lock(&philo->struct_data->forks[philo->right_fork]);
	philo->last_meal = get_time();
	print_status(get_time(), philo, "has taken a fork");
	print_status(get_time(), philo, "has taken a fork");
	print_status(get_time(), philo, "is eating");
	usleep(philo->struct_data->time_to_eat * 1000);
	pthread_mutex_unlock(&philo->struct_data->forks[philo->left_fork]);
	pthread_mutex_unlock(&philo->struct_data->forks[philo->right_fork]);
}