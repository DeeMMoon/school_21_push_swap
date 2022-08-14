/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_three.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gantedil <gantedil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 17:00:26 by gantedil          #+#    #+#             */
/*   Updated: 2022/08/14 20:00:04 by gantedil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/push_swap.h"

int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	ft_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

void	put_error(void)
{
	write(2, ERROR_MESSAGE, ER_MES_LEN);
	exit(EXIT_FAILURE);
}

void	delete_list(t_stack **head)
{
	t_stack	*next;

	while (*head)
	{
		next = (*head)->next;
		free(*head);
		*head = next;
	}
}

int	find_min_oper(int a, int b, int c, int d)
{
	int	min;

	min = 0;
	if (a <= b && a <= c && a <= d)
		min = a;
	else if (b <= a && b <= c && b <= d)
		min = b;
	else if (c <= a && c <= b && c <= d)
		min = c;
	else if (d <= a && d <= b && d <= c)
		min = d;
	return (min);
}
