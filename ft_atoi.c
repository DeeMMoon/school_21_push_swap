/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gantedil <gantedil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 17:04:18 by gantedil          #+#    #+#             */
/*   Updated: 2022/08/14 20:00:30 by gantedil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/push_swap.h"

int	num_len(long num)
{
	int	len;

	len = 0;
	if (num == 0)
		return (1);
	if (num < 0)
	{
		len++;
		num = -num;
	}
	while (num > 0)
	{
		num = num / 10;
		len++;
	}
	return (len);
}

int	str_len(char *str)
{
	int	len;

	len = 0;
	while (str[len])
	{
		if ((str[len] < '0' || str[len] > '9') && str[len] != '-')
			return (-1);
		if (str[len] == '-' && (str[len + 1] < '0' || str[len] > '9'))
			return (-1);
		len++;
	}
	return (len);
}

int	ft_atoi(const char *str)
{
	char	*p;
	long	i;
	long	num;
	int		minus;

	minus = 0;
	p = (char *)str;
	i = 0;
	if (p[i] == '-' || p[i] == '+')
	{
		if (p[i] == '-')
			minus++;
		i++;
	}
	num = 0;
	while (p[i] && p[i] >= '0' && p[i] <= '9')
		num = num * 10 + (p[i++] - '0');
	if (minus == 1)
		return (-num);
	return (num);
}
