/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 03:08:50 by azamario          #+#    #+#             */
/*   Updated: 2022/07/14 04:15:43 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <stdbool.h>
# include <limits.h>
# include <sys/time.h>

# define MIN_ARGS	5
# define MAX_ARGS	6

//error messages
# define USAGE "Usage: ./philo n_philo ms_to_die ms_to_eat ms_sleep [must_eat]"
# define NOT_UNINT "Arguments must be integers greater than 0"
# define PTHREAD_FAILURE "Could not create thread" 
# define JOIN_FAILURE "Could not join thread"

typedef struct s_data	t_data;

typedef struct s_philo
{
	int				left_fork;
	int				right_fork;
	int				philo_id;
	int				had_dinner;
	long int		last_dinner;
	pthread_mutex_t	mutex;
	pthread_t		thread;
	t_data			*struct_data;
}				t_philo;

struct			s_data
{
	int				number_of_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				to_dinner;
	int				checker;
	int				ate_dinner;
	long int		start_dinner;
	t_philo			*philo;
	pthread_t		monitor;
	pthread_mutex_t	*forks;
	pthread_mutex_t	meal;
	pthread_mutex_t	m_checker;
	pthread_mutex_t	print;
};

//error_check.c
bool		error_check(int argc, char **argv);
int			ft_isdigit(int c);

//utils.c
bool		error(char *message);
int			ft_atoi(const char *ptr);
void		ft_bzero(void *s, size_t n);
double		philos_atoi(const char *ptr);

//utils2.c
void		mutex_init(t_data *data);
void		mutex_destroy(t_data *data);
void		philo_satisfied(t_data *data);
void		philo_died(t_data *data, int i);

//utils_dinner.c
void		*died(void *param);
void		*one_philo(t_philo *philo);
void		eat(t_philo *philo);
long int	get_time(void);

//print_status.c
void		print_status(long int time_now, t_philo *philo, char *status);

#endif
