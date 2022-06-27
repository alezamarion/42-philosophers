/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 00:09:46 by azamario          #+#    #+#             */
/*   Updated: 2022/06/27 15:54:47 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philosophers.h"


static bool	only_unsigned_integers(int argc, char **argv, int i)
{
	(void)argc;
	(void)argv;
	(void)i;
	return (0);
	
}

bool	error(char *message)
{
	printf("%c", *message);
	return (false);
}

bool	error_check(int argc, char **argv)
{
	if (argc < MIN_ARGS || argc > MAX_ARGS)
		return (error(USAGE));
	if (!only_unsigned_integers(argc, argv, 0))
		return (error(NOT_UNINT));
	if (ft_atoi(argv[1]) > 200)
		return (error(PHILO_MAX));
	return (true);
}