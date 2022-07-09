/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 03:08:50 by azamario          #+#    #+#             */
/*   Updated: 2022/07/09 03:52:06 by azamario         ###   ########.fr       */
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
#define USAGE		"Usage: ./philo n_philo ms_to_die ms_to_eat ms_to_sleep [number_times_each_philo_have_to_dinner]"
#define NOT_UNINT	"Arguments must be integers greater than 0"
#define PTHREAD_FAILURE "Could not create thread" 

typedef struct s_data	t_data;		// 2

typedef struct			s_philo
{
	int				left_fork;
	int				right_fork;
	int				philo_ID;
	int				had_dinner;
	long int		last_dinner;
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
	int				have_to_dinner;
	int				checker;
	int				ate_dinner;
	long int		start_dinner;
	t_philo			*philo;
	pthread_t		monitor;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print;
};

//philosophers.c


//error_check.c
bool		error_check(int argc, char **argv);
bool		error(char *message);


//utils.c
int			ft_atoi(const char *ptr);
long int	get_time(void);
void		ft_bzero(void *s, size_t n);

//utils_dinner.c
void	*one_philo(t_philo *philo);
void	eat(t_philo *philo);
void	*died(void *param);

//print_status.c
void	print_status(long int time_now, t_philo *philo, char *status);







#endif
