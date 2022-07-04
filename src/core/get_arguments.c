/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arguments.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 21:07:08 by azamario          #+#    #+#             */
/*   Updated: 2022/07/04 21:26:27 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	get_arguments(int argc, char **argv, t_dinner *dinner)
{
	int	i;

	i = 0;
	ft_menset(dinner, 0, sizeof(t_dinner));
	while (++i < argc)
		assign_value(i, (long)philo_atoi(argv[i]), dinner);

	
}
