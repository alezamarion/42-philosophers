/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 02:22:50 by azamario          #+#    #+#             */
/*   Updated: 2022/07/10 23:51:53 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

bool	error(char *message)
{
	printf("%s\n", message);
	return (false);
}

int	ft_atoi(const char *ptr)
{
	int	res;
	int	sign;
	int	i;

	res = 0;
	sign = 1;
	i = 0;
	while (ptr[i] == ' ' || (ptr[i] >= '\t' && ptr[i] <= '\r' ))
		i++;
	if (ptr[i] == '+' || ptr[i] == '-')
	{
		if (ptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (ptr[i] >= '0' && ptr[i] <= '9')
	{
		res = ptr[i] - '0' + (res * 10);
		i++;
	}
	return (res * sign);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*s_s;
	size_t			i;

	i = 0;
	s_s = (unsigned char *)s;
	while (i < n)
	{
		s_s[i] = '\0';
		i++;
	}
}

/*
int	ft_isdigit(int c)
{
	if (c >= '0' && c <= 2147483647)
	{
		return (0);
	}
	return (1);
}
*/

double	philos_atoi(const char *ptr)
{
	double	number;

	number = 0;
	while (ft_isdigit(*ptr))
	{
		number *= 10;
		number += (*ptr - '0');
		ptr++;
	}
	return (number);
}
