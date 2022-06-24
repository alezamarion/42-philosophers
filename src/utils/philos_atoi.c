/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_atoi.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 00:07:44 by azamario          #+#    #+#             */
/*   Updated: 2022/06/25 00:07:46 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

double	philo_atoi(const char *nptr)
{
	double	number;

	number = 0;
	while (ft_isdigit(*nptr))
	{
		number *= 10;
		number += (*nptr - '0');
		nptr++;
	}
	return (number);
}
