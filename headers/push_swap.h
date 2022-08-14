#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "get_next_line_bonus.h"

# define MAX_INT 2147483647
# define MIN_INT -2147483648
# define ERROR_MESSAGE "Error\n"
# define ER_MES_LEN 6

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}					t_stack;

typedef struct s_data
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		len_a;
	int		len_b;
	int		elems;
	int		a_up;
	int		a_min_up;
	int		a_down;
	int		a_min_down;
	int		b_up;
	int		b_min_up;
	int		b_down;
	int		b_min_down;
}	t_data;

int		ft_atoi(const char *str);
int		str_len(char *str);
int		num_len(long num);
void	put_error(void);
void	create_stacks(t_data *data, int argc, char **argv);
void	s_symb(t_data *data, char *c, char symb);
void	ss(t_data *data);
void	p_symb(t_data *data, char *c, char symb);
void	r_symb(t_data *data, char *c, char symb);
void	rr(t_data *data);
void	rr_symb(t_data *data, char *c, char symb);
void	rrr(t_data *data);
void	pop(t_stack **stack);
void	push(t_stack **head, int value);
void	sort_to_three_a(t_data *data);
int		stack_len(t_stack *stack);
void	printList(t_stack *head);
void	big_sort(t_data *data);
t_stack	*get_last(t_stack *stack);
int		ft_max(int a, int b);
int		ft_min(int a, int b);
void	put_error(void);
int		find_best_elem(t_data *data, t_stack *b);
void	find_up_down(t_stack *stack, int value, int *up, int *down);
int		find_elem_position(t_stack *stack, int value);
void	final_sort(t_data *data);
void	delete_list(t_stack **head);
int		find_min_oper(int a, int b, int c, int d);
void	printlist(t_stack *head);
void	init_struct(t_data *data, int argc);
void	init_stack(t_data *data, int argc, char **argv);
void	push_to_a(t_stack *stack_a, int value);
void	s_symb_check(t_data *data, char symb);
void	ss_check(t_data *data);
void	p_symb_check(t_data *data, char symb);
void	rr_symb_check(t_data *data, char symb);
void	rrr_check(t_data *data);
void	r_symb_check(t_data *data, char symb);
void	rr_check(t_data *data);
int		is_sort(t_stack *stack);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	valid_line(int argc, char **argv);
#endif
