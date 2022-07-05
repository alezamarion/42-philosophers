/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_simulation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 20:40:56 by azamario          #+#    #+#             */
/*   Updated: 2022/07/05 21:20:10 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"


static void	define_forks(t_philo *philo, int i, long last_philo)
{
	philo[i].hand[LEFT] = i;				
	philo[i].hand[RIGHT] = i + 1;
	if (i == last_philo)
		philo[i].hand[RIGHT] = 1;	//a mão direita seria 201 (no caso de 200 philos)	
}

static void	init_philos(t_philo *philo, t_dinner *dinner, long number_of_philos, int i)
{
	while (++i <= number_of_philos)
	{
		ft_memset(&philo[i], 0, sizeof(t_philo));
		philo[i].index = i;
		define_forks(philo, i, number_of_philos);
		philo[i].dinner = dinner;
	}	
}

bool	init_simulation(t_dinner *dinner)
{
	t_philo		philo[dinner->number_of_philos];

	init_philos(philo, dinner, dinner->number_of_philos, 0);

	return true;
	
}