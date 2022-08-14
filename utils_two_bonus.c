/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_two_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gantedil <gantedil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 18:12:28 by gantedil          #+#    #+#             */
/*   Updated: 2022/08/14 20:00:02 by gantedil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/push_swap.h"

void	r_symb_check(t_data *data, char symb)
{
	t_stack	*tmp;
	t_stack	*last;

	if (symb == 'a' && data->len_a >= 2)
	{
		tmp = malloc(sizeof (t_stack));
		tmp->value = data->stack_a->value;
		tmp->next = NULL;
		pop(&data->stack_a);
		last = get_last(data->stack_a);
		last->next = tmp;
	}
	else if (data->len_b >= 2)
	{
		tmp = malloc(sizeof (t_stack));
		tmp->value = data->stack_b->value;
		tmp->next = NULL;
		pop(&data->stack_b);
		last = get_last(data->stack_b);
		last->next = tmp;
	}
}

void	rr_check(t_data *data)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;
	t_stack	*last;

	if (data->len_a >= 2)
	{
		tmp_a = malloc(sizeof (t_stack));
		tmp_a->value = data->stack_a->value;
		tmp_a->next = NULL;
		pop(&data->stack_a);
		last = get_last(data->stack_a);
		last->next = tmp_a;
	}
	else if (data->len_b >= 2)
	{
		tmp_b = malloc(sizeof (t_stack));
		tmp_b->value = data->stack_b->value;
		tmp_b->next = NULL;
		pop(&data->stack_b);
		last = get_last(data->stack_b);
		last->next = tmp_b;
	}
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (!*(unsigned char *)(s1 + i) || !*(unsigned char *)(s2 + i))
			return (*(unsigned char *)(s1 + i) - *(unsigned char *)(s2 + i));
		if (*(unsigned char *)(s1 + i) != *(unsigned char *)(s2 + i))
			return (*(unsigned char *)(s1 + i) - *(unsigned char *)(s2 + i));
		i++;
	}
	return (0);
}
