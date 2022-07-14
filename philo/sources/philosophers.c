/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 02:43:01 by azamario          #+#    #+#             */
/*   Updated: 2022/07/14 13:58:29 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
	int	i;

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
	data->time_to_eat = ft_atoi(argv[3]) * 1000;
	data->time_to_sleep = ft_atoi(argv[4]) * 1000;
	if (argc > 5)
		data->to_dinner = ft_atoi(argv[5]);
	else
		data->to_dinner = 0;
	data->forks = NULL;
	data->philo = malloc(data->number_of_philos * sizeof(t_philo));
	data->forks = malloc(data->number_of_philos * sizeof(pthread_mutex_t));
	if (data->forks == NULL || data->philo == NULL)
	{
		printf("Could not malloc struct\n");
		return ;
	}
	data->ate_dinner = 0;
	ft_bzero(data->philo, sizeof(t_philo));
	return (philo_info(data));
}

/*
	passa a struct para a variável philo
	%2: se philo_id é par, espera alguns ms para que threads impares 
		peguem o garfo dela e do philo par
	checker 1 == alguém morreu -> vai comer, dormir e pensar
	usleep: dorme pelo tempo que passou na linha de comando
*/
void	*routine(void *param)
{
	t_philo	*philo;

	philo = param;
	if (philo->struct_data->number_of_philos == 1)
		return (one_philo(philo));
	while (true)
	{
		if (philo->philo_id % 2 == 0)
			usleep(1600);
		eat(philo);
		print_status(get_time(), philo, "is sleeping 💤");
		usleep(philo->struct_data->time_to_sleep);
		print_status(get_time(), philo, "is thinking 🤔");
		pthread_mutex_lock(&philo->struct_data->m_checker);
		if (philo->struct_data->checker == 1)
		{
			pthread_mutex_unlock(&philo->struct_data->m_checker);
			break ;
		}
		pthread_mutex_unlock(&philo->struct_data->m_checker);
	}
	return (NULL);
}

int	create_philo(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->number_of_philos)
	{
		if (pthread_create(&data->philo[i].thread, NULL, &routine,
				&data->philo[i]) != 0)
			return (error(PTHREAD_FAILURE));
	}	
	return (1);
}

/*
	data.print = tipo pthread_mutex_t, não é lugar de armazenamento,
		ele bloqueia o código da impressão.
	mute_init -> mutex_lock -> mutex_unlock ->mutex_destroy
	create_philo: realiza while para criar thread de cada philo
	pthread_create: cria a thread do monitor
	pthread_join: realiza um while para dar join em cada philo
		- aí dispara as threads
	pthread_join_monitor: as threads começam a funcionar aqui, 
		com o join as duas rotinas
	acontecem: jantar e a verificação se alguém morreu
*/

int	main(int argc, char **argv)
{
	t_data	data;
	int		i;

	i = -1;
	init_mutex(&data);
	if (!error_check(argc, argv))
		return (EXIT_FAILURE);
	data.start_dinner = get_time();
	start_struct(&data, argc, argv);
	create_philo(&data);
	if (pthread_create(&data.monitor, NULL, &died, &data) != 0)
		return (error(PTHREAD_FAILURE));
	if (pthread_join(data.monitor, NULL) != 0)
		return (error(JOIN_FAILURE));
	while (++i < data.number_of_philos)
	{
		if (pthread_join(data.philo[i].thread, NULL) != 0)
			return (error(JOIN_FAILURE));
	}
	usleep(1000);
	destroy_mutex(&data);
	free(data.philo);
	free(data.forks);
	return (0);
}

/*
	Ajustar:
	1 800 200 200	: OK should not eat and die
	5 800 200 200 	: OK no one should die
	5 800 200 200 7 : apenas 34 comem
	4 410 200 200	: um philo morre (não deveria)
	4 310 200 100	: OK um philo deve morrer
	2 310 200 100	: OK death delayed no more than 10ms
	
	1 - debugar
	2 - Makefile
	3 - Data Race: estudar e testar com Valgrind
	4 - Fazer o fluxo
*/
