/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 02:43:01 by azamario          #+#    #+#             */
/*   Updated: 2022/07/08 03:51:53 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	philo_info(t_data *data)
{
	int i;
	
	i = 0;
	while (i < data->number_of_philos)
	{
		data->philo[i].n_philo = i + i;
		data->philo[i].left_fork = i;
		data->philo[i].right_fork = i + i;
		data->philo[i].struct_data = data;		// 3
		data->philo[i].last_meal = get_time();
		data->philo[i].n_meals = 0;
		if (i + 1 == data->number_of_philos)
			data->philo[i].right_fork = 0;
		pthread_mutex_init(&data->forks[i], NULL);
		i++;
	}
}

void	start_struct(t_data *data, int argc, char **argv)
{
	data->number_of_philos = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argc > 5)
		data->must_eat = ft_atoi(argv[5]);
	else
		data->must_eat = 0;
	data->forks = NULL;
	data->philo = malloc(data->number_of_philos * sizeof(t_philo));
	data->forks = malloc(data->number_of_philos * sizeof(pthread_mutex_t));
	data->ate_meal = 0;
	ft_bzero(data->philo, sizeof(t_philo));
	return (philo_info(data));
}

void	*routine(void *param) 	//5
{
	t_philo	*philo;

	philo = param;
	if (philo->struct_data->number_of_philos == 1)
		return (one_philo(philo));
	if (philo->n_philo % 2 == 0)
		usleep(1600);
	while (philo->struct_data->checker != 1)
	{
		eat(philo);
		print_status(get_time(), philo, "is sleeping");
		usleep(philo->struct_data->time_to_sleep * 1000);
		print_status(get_time(), philo, "is thinking");
		philo->n_meals++;
	}
	return (NULL);
}

int		create_philo(t_data *data)
{
	int i;
	
	i = -1;
	while (++i < data->number_of_philos)
		pthread_create(&data->philo[i].thread, NULL, &routine, &data->philo[i]); //checar erros para ver se as threads foram criadas
	return (1);
}

int		main(int argc, char **argv)
{
	t_data	data;
	int		i;

	i = 0;
	pthread_mutex_init(&data.print, NULL);
	if (!error_check(argc, argv))
		return (EXIT_FAILURE);
	data.start_meal = get_time();
	start_struct(&data, argc, argv);
	create_philo(&data);

	return (0);
	
}