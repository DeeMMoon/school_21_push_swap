#include "headers/push_swap.h"

void	push_to_a(t_stack *stack_a, int value)
{
	t_stack	*current;

	current = stack_a;
	while (current->next != NULL)
		current = current->next;
	current->next = malloc(sizeof (t_stack));
	current->next->value = value;
	current->next->next = NULL;
}

void	init_stack(t_data *data, int argc, char **argv)
{
	int	i;

	i = 1;
	data->stack_a->value = ft_atoi(argv[1]);
	data->stack_a->next = NULL;
	while ((i + 1) < argc)
	{
		push_to_a(data->stack_a, ft_atoi(argv[i + 1]));
		i++;
	}
}

void	create_stacks(t_data *data, int argc, char **argv)
{
	data->stack_a = malloc(sizeof(*data->stack_a));
	data->stack_b = NULL;
	init_stack(data, argc, argv);
	while (data->len_a > 3)
	{
		p_symb(data, "pb\n", 'b');
		data->len_b++;
		data->len_a--;
	}
	if (data->len_a == 2)
		s_symb(data, "sa\n", 'a');
	else
	{
		sort_to_three_a(data);
		big_sort(data);
	}
	delete_list(&data->stack_a);
}
