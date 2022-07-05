/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 03:08:50 by azamario          #+#    #+#             */
/*   Updated: 2022/07/05 21:13:14 by azamario         ###   ########.fr       */
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

#define MIN_ARGS	5
#define MAX_ARGS	6

#define LEFT		0
#define RIGHT		1

typedef struct	s_time
{
	long	time_to_die;
	long	time_to_eat;
	long	time_to_sleep;
	long	must_eat;
}				t_time;

typedef struct s_dinner
{
	long	number_of_philos;
	t_time	time;
	
	
}				t_dinner;

//cada filosofo
typedef struct s_philo
{
	int			index;
	long		last_meal;
	int			eaten_times;
	int			hand[2];
	t_dinner	*dinner;
}				t_philo;


//error messages
#define USAGE		"Usage: ./philo n_philo ms_to_die ms_to_eat ms_to_sleep [number_times_each_philo_must_eat]"
#define NOT_UNINT	"Arguments must be integers greater than 0"

//philos.c

//init_simulation.c
bool			init_simulation(t_dinner *dinner);


//get_arguments.c
void			get_arguments(int argc, char **argv, t_dinner *dinner);

//error_check
bool			error_check(int argc, char **argv);
bool			error(char *message);

//utils
double			philos_atoi(const char *ptr);
int				ft_isdigit(int c);
void			*ft_memset(void *b, int c, size_t len);

#endif
