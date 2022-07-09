/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 02:33:00 by azamario          #+#    #+#             */
/*   Updated: 2022/07/09 02:54:12 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	print_status(long int time_now, t_philo *philo, char *status)
{
	pthread_mutex_lock(&philo->struct_data->print);
	if (philo->struct_data->checker != 1)
		printf("%6ld %3d %s\n", time_now - philo->struct_data->start_meal, 
			philo->philo_ID, status);
	pthread_mutex_unlock(&philo->struct_data->print);	
}
