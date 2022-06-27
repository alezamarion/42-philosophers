/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 03:08:50 by azamario          #+#    #+#             */
/*   Updated: 2022/06/27 15:04:04 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS.H
# define PHILOSOPHERS.H

#include <stlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

//
#define MIN_ARGS	5
#define MAX_ARGS	6

//error messages
#define USAGE		"Usage: ./philo n_philo ms_to_die ms_to_ezt ms_to_sleep"
#define NOT_UNINT	"Arguments must be greater than 0"
#define	PHILO_MAX	"Maximum number of philos: 200"	

//core
char	error_check(int argc, cher **argv)
char	error(char *message)




#endif
