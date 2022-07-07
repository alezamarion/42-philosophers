/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 02:43:01 by azamario          #+#    #+#             */
/*   Updated: 2022/07/07 03:16:41 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"







int		main(int argc, char **argv)
{
	t_data	data;
	int		i;

	i = 0;
	pthread_mutex_init(&data.print, NULL);
	if (!error_check(argc, argv))
		return (EXIT_FAILURE);





	
}