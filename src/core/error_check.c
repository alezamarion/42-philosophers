/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 00:09:46 by azamario          #+#    #+#             */
/*   Updated: 2022/06/27 15:00:12 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


char	error(char *message)
{
	printf("%s", *message)
	return (EXIT_FAILURE);
}

char	error_check(int argc, cher **argv)
{
	if (argc < MIN_ARGS || argc > MAX_ARGS)
		return (error(USAGE));
	if (!only_unsigned_integers(argc, argv, 0))
		return (error(NOT_UNINT));
	if (ft_atoi(argv[1]) > 200)
		return (error(PHILO_MAX))
}