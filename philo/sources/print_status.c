/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 02:33:00 by azamario          #+#    #+#             */
/*   Updated: 2022/07/13 22:26:50 by azamario         ###   ########.fr       */
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
	pthread_mutex_lock(&philo->struct_data->m_checker);
	pthread_mutex_unlock(&philo->struct_data->print);
}
