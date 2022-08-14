#include "headers/push_swap.h"

int	check_error(char *line)
{
	if (!ft_strncmp(line, "sa\n", 3))
		return (0);
	else if (!ft_strncmp(line, "sb\n", 3))
		return (0);
	else if (!ft_strncmp(line, "ss\n", 3))
		return (0);
	else if (!ft_strncmp(line, "pa\n", 3))
		return (0);
	else if (!ft_strncmp(line, "pb\n", 3))
		return (0);
	else if (!ft_strncmp(line, "ra\n", 3))
		return (0);
	else if (!ft_strncmp(line, "rb\n", 3))
		return (0);
	else if (!ft_strncmp(line, "rr\n", 3))
		return (0);
	else if (!ft_strncmp(line, "rra\n", 4))
		return (0);
	else if (!ft_strncmp(line, "rrb\n", 4))
		return (0);
	else if (!ft_strncmp(line, "rrr\n", 4))
		return (0);
	else
		return (1);
}

void	create_stacks_checker(t_data *data, int argc, char **argv)
{
	data->stack_a = malloc(sizeof(*data->stack_a));
	data->stack_b = NULL;
	init_stack(data, argc, argv);
}

void	do_somth(t_data *data, char *line)
{
	if (!ft_strncmp(line, "sa\n", 3))
		s_symb_check(data, 'a');
	else if (!ft_strncmp(line, "sb\n", 3))
		s_symb_check(data, 'b');
	else if (!ft_strncmp(line, "ss\n", 3))
		ss_check(data);
	else if (!ft_strncmp(line, "pa\n", 3))
		p_symb_check(data, 'a');
	else if (!ft_strncmp(line, "pb\n", 3))
		p_symb_check(data, 'b');
	else if (!ft_strncmp(line, "ra\n", 3))
		r_symb_check(data, 'a');
	else if (!ft_strncmp(line, "rb\n", 3))
		r_symb_check(data, 'b');
	else if (!ft_strncmp(line, "rr\n", 3))
		rr_check(data);
	else if (!ft_strncmp(line, "rra\n", 4))
		rr_symb_check(data, 'a');
	else if (!ft_strncmp(line, "rrb\n", 4))
		rr_symb_check(data, 'b');
	else if (!ft_strncmp(line, "rrr\n", 4))
		rrr_check(data);
}

void	main_util(t_data *data, int er_flag)
{
	if (er_flag > 0)
	{
		delete_list(&data->stack_a);
		delete_list(&data->stack_b);
		free(data);
		put_error();
	}
	if (is_sort(data->stack_a) && data->len_b == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	delete_list(&data->stack_a);
	delete_list(&data->stack_b);
}

int	main(int argc, char **argv)
{
	char	*line;
	int		er_flag;
	t_data	*data;

	if (argc <= 1)
		return (0);
	valid_line(argc, argv);
	data = (t_data *) malloc(sizeof(t_data));
	if (!data)
		exit(EXIT_FAILURE);
	init_struct(data, argc);
	create_stacks_checker(data, argc, argv);
	er_flag = 0;
	line = get_next_line(0);
	while (line)
	{
		er_flag += check_error(line);
		if (er_flag == 0)
			do_somth(data, line);
		free(line);
		line = get_next_line(0);
	}
	main_util(data, er_flag);
	free(data);
	return (0);
}
