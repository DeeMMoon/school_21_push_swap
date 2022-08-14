/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_to_three_a.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gantedil <gantedil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 17:10:16 by gantedil          #+#    #+#             */
/*   Updated: 2022/08/14 20:00:07 by gantedil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/push_swap.h"

void	sort_to_three_a(t_data *data)
{
	if (data->stack_a->value > data->stack_a->next->value
		&& data->stack_a->value > data->stack_a->next->next->value)
	{
		r_symb(data, "ra\n", 'a');
		if (data->stack_a->value > data->stack_a->next->value)
			s_symb(data, "sa\n", 'a');
		return ;
	}
	if (data->stack_a->value < data->stack_a->next->value
		&& data->stack_a->next->value > data->stack_a->next->next->value)
	{
		rr_symb(data, "rra\n", 'a');
		if (data->stack_a->value > data->stack_a->next->value)
			s_symb(data, "sa\n", 'a');
		return ;
	}
	if (data->stack_a->value < data->stack_a->next->next->value
		&& data->stack_a->next->value < data->stack_a->next->next->value
		&& data->stack_a->value > data->stack_a->next->value)
		s_symb(data, "sa\n", 'a');
}
