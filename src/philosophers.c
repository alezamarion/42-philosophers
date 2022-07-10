/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 02:43:01 by azamario          #+#    #+#             */
/*   Updated: 2022/07/10 15:48:22 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/*
	while para a criação de cada philo na struct
	insere os valores nas variáveis da struct
	cria um número de ID para cada philo	(philo_id)
	data->philo[i].struct_data = data:
		valores da struct data entram na struct philo->data
	
	philo[0]	philo[1]	philo[2]
	id 1		id 2		id 3
	left 0		left 1		left 2
	right 1		right 2		right 0
	
	pthread_mutex_init(&data->forks[i], NULL): cria o mutex de cada garfo
*/
void	philo_info(t_data *data)
{
	int i;
	
	i = 0;
	while (i < data->number_of_philos)
	{
		data->philo[i].philo_id = i + 1;
		data->philo[i].left_fork = i;
		data->philo[i].right_fork = i + 1;
		data->philo[i].struct_data = data;
		data->philo[i].last_dinner = get_time();
		data->philo[i].had_dinner = 0;
		if (i + 1 == data->number_of_philos)
			data->philo[i].right_fork = 0;
		pthread_mutex_init(&data->forks[i], NULL);
		i++;
	}
}

/*
	colocar os argumentos da linha de comando na struct
	malloca espaço na struct t_philo, onde vai ser criado todos os philos
	malloca espaço para a struct pthread_mutex_t
	zera a struct que vai acomodar os philos
*/
void	start_struct(t_data *data, int argc, char **argv)
{																		
	data->number_of_philos = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argc > 5)
		data->have_to_dinner = ft_atoi(argv[5]);
	else
		data->have_to_dinner = 0;
	data->forks = NULL;
	data->philo = malloc(data->number_of_philos * sizeof(t_philo));
	data->forks = malloc(data->number_of_philos * sizeof(pthread_mutex_t));
	data->ate_dinner = 0;
	ft_bzero(data->philo, sizeof(t_philo));
	return (philo_info(data));
}

/*
	passa a struct para a variável philo
	%2: se philo_id é par, espera alguns ms para que threads impares 
		peguem o garfo dela e do philo par
	checker 1 == alguém morreu -> vai comer, dormir e pensar
	usleep: dorme pelo tempo que pasosu na linha de comando
*/
void	*routine(void *param)
{
	t_philo	*philo;

	philo = param;
	if (philo->struct_data->number_of_philos == 1)
		return (one_philo(philo));
	if (philo->philo_id % 2 == 0)
		usleep(1600);
	while (philo->struct_data->checker != 1)
	{
		eat(philo);
		print_status(get_time(), philo, "is sleeping");
		usleep(philo->struct_data->time_to_sleep * 1000);
		print_status(get_time(), philo, "is thinking");
		philo->had_dinner++;
	}
	return (NULL);
}

int		create_philo(t_data *data)
{
	int i;
	
	i = -1;
	while (++i < data->number_of_philos)
	{
		if (pthread_create(&data->philo[i].thread, NULL, &routine, &data->philo[i]) != 0)
			return (error(PTHREAD_FAILURE));
	}	
	return (1);
}

/*
	data.print = tipo pthread_mutex_t
	create_philo: realiza while para criar thread de cada philo
	pthread_create: cria a thread do monitor
	pthread_join: realiza um while para dar join em cada philo - aí dispara as threads
	pthread_join_monitor: as threads começam a funcionar aqui, com o join as duas rotinas
	acontecem: jantar e a verificação se alguém morreu
*/
int		main(int argc, char **argv)
{
	t_data	data;
	int		i;

	i = 0;
	pthread_mutex_init(&data.print, NULL);
	if (!error_check(argc, argv))
		return (EXIT_FAILURE);
	data.start_dinner = get_time();
	start_struct(&data, argc, argv);
	create_philo(&data);
	if (pthread_create(&data.monitor, NULL, &died, &data) != 0)
		return (error(PTHREAD_FAILURE));
	while (++i < data.number_of_philos)
		pthread_join(data.philo[i].thread, NULL);
	pthread_join(data.monitor, NULL);
	free(data.philo);
	free(data.forks);
	return (0);	
}
