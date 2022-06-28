/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 03:08:50 by azamario          #+#    #+#             */
/*   Updated: 2022/06/28 02:58:04 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdbool.h>
#include <limits.h>
#include <sys/time.h>

//
#define MIN_ARGS	5
#define MAX_ARGS	6

//error messages
#define USAGE		"Usage: ./philo n_philo ms_to_die ms_to_eat ms_to_sleep"
#define NOT_UNINT	"Arguments must be greater than 0"
#define	PHILO_MAX	"Maximum number of philos: 200"	

//philos.c


//error_check
bool			error_check(int argc, char **argv);
bool			error(char *message);

//utils
int		ft_atoi(const char *str);
double	philo_atoi(const char *ptr);
int		ft_isdigit(int c);
void	*ft_memset(void *b, int c, size_t len);

#endif
