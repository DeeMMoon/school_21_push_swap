#include "headers/push_swap.h"

void	ft_up_rotate(t_data *data)
{
	if (data->a_min_up >= data->b_min_up)
	{
		while (data->b_min_up--)
		{
			rr(data);
			data->a_min_up--;
		}
		while (data->a_min_up--)
			r_symb(data, "ra\n", 'a');
	}
	else
	{
		while (data->a_min_up--)
		{
			rr(data);
			data->b_min_up--;
		}
		while (data->b_min_up--)
			r_symb(data, "rb\n", 'b');
	}
	p_symb(data, "pa\n", 'a');
}

void	ft_down_rotate(t_data *data)
{
	if (data->a_min_down >= data->b_min_down)
	{
		while (data->b_min_down--)
		{
			rrr(data);
			data->a_min_down--;
		}
		while (data->a_min_down--)
			rr_symb(data, "rra\n", 'a');
	}
	else
	{
		while (data->a_min_down--)
		{
			rrr(data);
			data->b_min_down--;
		}
		while (data->b_min_down--)
			rr_symb(data, "rrb\n", 'b');
	}
	p_symb(data, "pa\n", 'a');
}

void	ft_min_d_rotate(t_data *data)
{
	if (data->a_min_up <= data->a_min_down)
	{
		while (data->a_min_up--)
			r_symb(data, "ra\n", 'a');
		while (data->b_min_down--)
			rr_symb(data, "rrb\n", 'b');
	}
	else
	{
		while (data->a_min_down--)
			rr_symb(data, "rra\n", 'a');
		while (data->b_min_up--)
			r_symb(data, "rb\n", 'b');
	}
	p_symb(data, "pa\n", 'a');
}

void	ft_put_elem(t_data *data)
{
	int	up;
	int	down;
	int	mid_d1;
	int	mid_d2;

	up = ft_max(data->a_min_up, data->b_min_up);
	down = ft_max(data->a_min_down, data->b_min_down);
	mid_d1 = data->a_min_up + data->b_min_down;
	mid_d2 = data->a_min_down + data->b_min_up;
	if (up == find_min_oper(up, down, mid_d1, mid_d2))
		ft_up_rotate(data);
	else if (down == find_min_oper(up, down, mid_d1, mid_d2))
		ft_down_rotate(data);
	else if (mid_d1 == find_min_oper(up, down, mid_d1, mid_d2))
		ft_min_d_rotate(data);
	else if (mid_d2 == find_min_oper(up, down, mid_d1, mid_d2))
		ft_min_d_rotate(data);
}

void	big_sort(t_data *data)
{
	while (data->len_b != 0)
	{
		find_best_elem(data, data->stack_b);
		ft_put_elem(data);
		data->len_b--;
		data->len_a++;
	}
	final_sort(data);
}
