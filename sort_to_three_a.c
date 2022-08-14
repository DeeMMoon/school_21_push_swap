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
