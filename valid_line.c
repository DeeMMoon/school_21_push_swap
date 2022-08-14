/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gantedil <gantedil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 18:59:30 by gantedil          #+#    #+#             */
/*   Updated: 2022/08/14 19:59:56 by gantedil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/push_swap.h"

void	init_struct(t_data *data, int argc)
{
	data->len_a = argc - 1;
	data->len_b = 0;
	data->stack_a = NULL;
	data->stack_b = NULL;
	data->elems = argc - 1;
	data->a_min_up = 0;
	data->a_min_down = 0;
	data->b_min_up = 0;
	data->b_min_down = 0;
}

void	if_repeat(long *nums, int index)
{
	int	j;

	j = 0;
	while (j < index)
	{
		if (nums[j] == nums[index])
		{
			free(nums);
			put_error();
		}
		j++;
	}
}

int	if_sort(long *nums, int argc)
{
	int	flag;
	int	i;

	flag = 0;
	i = 0;
	while (i < argc - 2)
	{
		if (nums[i] > nums[i + 1])
			flag++;
		i++;
	}
	return (flag);
}

void	valid_line(int argc, char **argv)
{
	long	*nums;
	int		i;

	nums = malloc(sizeof (long) * (argc - 1));
	i = 0;
	while ((i + 1) < argc)
	{
		nums[i] = ft_atoi(argv[i + 1]);
		if ((num_len(nums[i]) != str_len(argv[i + 1]))
			|| nums[i] > MAX_INT || nums[i] < MIN_INT)
		{
			free(nums);
			put_error();
		}
		if_repeat(nums, i);
		i++;
	}
	if (if_sort(nums, argc) == 0)
	{
		free(nums);
		exit(EXIT_SUCCESS);
	}
	free (nums);
}