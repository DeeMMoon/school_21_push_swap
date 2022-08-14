/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gantedil <gantedil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 17:42:58 by gantedil          #+#    #+#             */
/*   Updated: 2022/08/14 20:00:33 by gantedil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/push_swap.h"

int	find_min_elem(t_stack *stack)
{
	int	min;

	min = stack->value;
	while (stack)
	{
		if (min > stack->value)
			min = stack->value;
		stack = stack->next;
	}
	return (min);
}

void	final_sort(t_data *data)
{
	int	up;
	int	down;
	int	min;

	min = find_min_elem(data->stack_a);
	find_up_down (data->stack_a, min, &up, &down);
	if (up < down)
	{
		while (up--)
			r_symb(data, "ra\n", 'a');
	}
	else
	{
		while (down--)
			rr_symb(data, "rra\n", 'a');
	}
}
