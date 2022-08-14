/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gantedil <gantedil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 17:13:32 by gantedil          #+#    #+#             */
/*   Updated: 2022/08/14 19:59:59 by gantedil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/push_swap.h"

void	s_symb(t_data *data, char *c, char symb)
{
	int	value;

	if (symb == 'a')
	{
		value = data->stack_a->value;
		data->stack_a->value = data->stack_a->next->value;
		data->stack_a->next->value = value;
	}
	else
	{
		value = data->stack_b->value;
		data->stack_b->value = data->stack_b->next->value;
		data->stack_b->next->value = value;
	}
	write(1, c, 3);
}

void	ss(t_data *data)
{
	int	value;

	value = 0;
	if (data->len_a >= 2 && data->len_b >= 2)
	{
		value = data->stack_a->value;
		data->stack_a->value = data->stack_a->next->value;
		data->stack_a->next->value = value;
		value = data->stack_b->value;
		data->stack_b->value = data->stack_b->next->value;
		data->stack_b->next->value = value;
	}
	write(1, "ss\n", 3);
}

void	p_symb(t_data *data, char *c, char symb)
{
	t_stack	*new;

	if (symb == 'a' && data->len_b > 0)
	{
		new = data->stack_b;
		data->stack_b = data->stack_b->next;
		new->next = data->stack_a;
		data->stack_a = new;
	}
	else if (data->len_a > 0)
	{
		new = data->stack_a;
		data->stack_a = data->stack_a->next;
		new->next = data->stack_b;
		data->stack_b = new;
	}
	write(1, c, 3);
}

void	rr_symb(t_data *data, char *c, char symb)
{
	t_stack	*tmp;

	if (symb == 'a' && data->len_a > 1)
	{
		tmp = data->stack_a;
		while (tmp->next->next != NULL)
			tmp = tmp->next;
		tmp->next->next = data->stack_a;
		data->stack_a = tmp->next;
		tmp->next = NULL;
	}
	else if (data->len_b > 1)
	{
		tmp = data->stack_b;
		while (tmp->next->next != NULL)
			tmp = tmp->next;
		tmp->next->next = data->stack_b;
		data->stack_b = tmp->next;
		tmp->next = NULL;
	}
	write(1, c, 4);
}

void	rrr(t_data *data)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;

	if (data->len_a > 1)
	{
		tmp_a = data->stack_a;
		while (tmp_a->next->next != NULL)
			tmp_a = tmp_a->next;
		tmp_a->next->next = data->stack_a;
		data->stack_a = tmp_a->next;
		tmp_a->next = NULL;
	}
	if (data->len_b > 1)
	{
		tmp_b = data->stack_b;
		while (tmp_b->next->next != NULL)
			tmp_b = tmp_b->next;
		tmp_b->next->next = data->stack_b;
		data->stack_b = tmp_b->next;
		tmp_b->next = NULL;
	}
	write(1, "rrr\n", 4);
}
