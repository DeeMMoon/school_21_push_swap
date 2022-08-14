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
