#include "headers/push_swap.h"

void	s_symb_check(t_data *data, char symb)
{
	int	value;

	if (symb == 'a' && data->len_a >= 2)
	{
		value = data->stack_a->value;
		data->stack_a->value = data->stack_a->next->value;
		data->stack_a->next->value = value;
	}
	else if (data->len_b >= 2)
	{
		value = data->stack_b->value;
		data->stack_b->value = data->stack_b->next->value;
		data->stack_b->next->value = value;
	}
}

void	ss_check(t_data *data)
{
	int	value;

	value = 0;
	if (data->len_a >= 2)
	{
		value = data->stack_a->value;
		data->stack_a->value = data->stack_a->next->value;
		data->stack_a->next->value = value;
	}
	if (data->len_b >= 2)
	{
		value = data->stack_b->value;
		data->stack_b->value = data->stack_b->next->value;
		data->stack_b->next->value = value;
	}
}

void	p_symb_check(t_data *data, char symb)
{
	t_stack	*new;

	if (symb == 'a' && data->len_b > 0)
	{
		new = data->stack_b;
		data->stack_b = data->stack_b->next;
		new->next = data->stack_a;
		data->stack_a = new;
		data->len_a++;
		data->len_b--;
	}
	else if (data->len_a > 0)
	{
		new = data->stack_a;
		data->stack_a = data->stack_a->next;
		new->next = data->stack_b;
		data->stack_b = new;
		data->len_a--;
		data->len_b++;
	}
}

void	rr_symb_check(t_data *data, char symb)
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
}

void	rrr_check(t_data *data)
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
}
