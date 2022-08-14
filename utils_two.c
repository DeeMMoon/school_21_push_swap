#include "headers/push_swap.h"

t_stack	*get_last(t_stack *stack)
{
	if (stack == NULL)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

void	pop(t_stack **stack)
{
	t_stack	*prev;

	prev = (*stack);
	(*stack) = (*stack)->next;
	free(prev);
}

void	push(t_stack **head, int value)
{
	t_stack	*new;

	new = malloc(sizeof (t_stack));
	new->value = value;
	new->next = (*head);
	(*head) = new;
}

void	r_symb(t_data *data, char *c, char symb)
{
	t_stack	*tmp;
	t_stack	*last;

	tmp = malloc(sizeof (t_stack));
	if (!tmp)
		put_error();
	if (symb == 'a' && data->len_a >= 2)
	{
		tmp->value = data->stack_a->value;
		tmp->next = NULL;
		pop(&data->stack_a);
		last = get_last(data->stack_a);
		last->next = tmp;
	}
	else if (data->len_b >= 2)
	{
		tmp->value = data->stack_b->value;
		tmp->next = NULL;
		pop(&data->stack_b);
		last = get_last(data->stack_b);
		last->next = tmp;
	}
	write(1, c, 3);
}

void	rr(t_data *data)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;
	t_stack	*last;

	if (data->len_a >= 2 && data->len_b >= 2)
	{
		tmp_a = malloc(sizeof (t_stack));
		tmp_b = malloc(sizeof (t_stack));
		if (!tmp_a || !tmp_b)
			put_error();
		tmp_a->value = data->stack_a->value;
		tmp_a->next = NULL;
		pop(&data->stack_a);
		last = get_last(data->stack_a);
		last->next = tmp_a;
		tmp_b->value = data->stack_b->value;
		tmp_b->next = NULL;
		pop(&data->stack_b);
		last = get_last(data->stack_b);
		last->next = tmp_b;
	}
	write(1, "rr\n", 3);
}
