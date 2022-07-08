/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 03:08:50 by azamario          #+#    #+#             */
/*   Updated: 2022/07/08 02:52:09 by azamario         ###   ########.fr       */
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

//error messages
#define USAGE		"Usage: ./philo n_philo ms_to_die ms_to_eat ms_to_sleep [number_times_each_philo_must_eat]"
#define NOT_UNINT	"Arguments must be integers greater than 0"

typedef struct s_data	t_data;		// 2

typedef struct			s_philo
{
	int				left_fork;
	int				right_fork;
	int				n_philo;
	int				n_meals;
	long int		last_meal;
	pthread_mutex_t	mutex;
	pthread_t		thread;
	t_data			*struct_data;
}						t_philo;

struct			s_data
{
	int				number_of_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat;
	int				checker;
	int				ate_meal;
	long int		start_meal;
	t_philo			*philo;
	pthread_t		monitor;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print;
};

//philosophers.c


//error_check.c
bool		error_check(int argc, char **argv);

//utils.c
int			ft_atoi(const char *ptr);
long int	get_time(void);
void		ft_bzero(void *s, size_t n);

//utils_dinner.c
void	*one_philo(t_philo *philo);

//print_status.c
void	print_status(long int time_now, t_philo *philo, char *status);







#endif
