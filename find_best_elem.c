#include "headers/push_swap.h"

int	find_elem_position(t_stack *stack, int value)
{
	int		min;
	int		prev;
	t_stack	*last;

	last = get_last(stack);
	prev = last->value;
	min = stack->value;
	while (stack)
	{
		if (min > stack->value)
			min = stack->value;
		if (stack->value > value && value > prev)
			return (stack->value);
		prev = stack->value;
		stack = stack->next;
	}
	return (min);
}

void	find_up_down(t_stack *stack, int value, int *up, int *down)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (stack)
	{
		if (stack->value == value)
		{
			(*up) = i;
			k = 0;
		}
		stack = stack->next;
		k++;
		i++;
	}
	(*down) = k;
}

int	find_elem_min_operation(t_data *data, t_stack *b, int value)
{
	int	up;
	int	down;
	int	min_d1;
	int	min_d2;

	find_up_down(data->stack_a, find_elem_position(data->stack_a, b->value),
		&data->a_up, &data->a_down);
	find_up_down(data->stack_b, value, &data->b_up, &data->b_down);
	up = ft_max (data->a_up, data->b_up);
	down = ft_max(data->a_down, data->b_down);
	min_d1 = data->a_up + data->b_down;
	min_d2 = data->a_down + data->b_up;
	return (find_min_oper(up, down, min_d1, min_d2));
}

void	init_param(t_data *data)
{
	data->a_min_up = data->a_up;
	data->a_min_down = data->a_down;
	data->b_min_up = data->b_up;
	data->b_min_down = data->b_down;
}

int	find_best_elem(t_data *data, t_stack *b)
{
	int	elem;
	int	min_operation;

	min_operation = find_elem_min_operation(data, b, b->value);
	init_param(data);
	elem = b->value;
	while (b)
	{
		if (min_operation > find_elem_min_operation(data, b, b->value))
		{
			init_param(data);
			elem = b->value;
			min_operation = find_elem_min_operation(data, b, b->value);
		}
		b = b->next;
	}
	return (elem);
}
