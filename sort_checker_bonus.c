/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_checker_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gantedil <gantedil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 18:23:28 by gantedil          #+#    #+#             */
/*   Updated: 2022/08/14 20:00:09 by gantedil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/push_swap.h"

int	is_sort(t_stack *stack)
{
	t_stack	*prev;

	if (stack == NULL)
		return (1);
	prev = stack;
	stack = stack->next;
	while (stack)
	{
		if (stack->value < prev->value)
			return (0);
		prev = stack;
		stack = stack->next;
	}
	return (1);
}
