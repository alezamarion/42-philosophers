/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 03:08:39 by azamario          #+#    #+#             */
/*   Updated: 2022/06/14 03:10:48 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	*routine()
{
	printf("Test from threads\n");
}

int		main(int argc, char *argv[])
{
	pthread_t	thread1;

	//to initialize an thread
	pthread_create(&thread1, NULL, &routine, NULL);

	return (0);
}


//para compilar: gcc -g -pthread thread.c -o thread