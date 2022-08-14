NAME = push_swap

NAME_B = checker

SRC_NAME 	= main.c big_sort.c create_stacks.c final_sort.c find_best_elem.c ft_atoi.c \
					sort_to_three_a.c utils_three.c utils_two.c utils.c valid_line.c

SRC_B		=  checker_bonus.c get_next_line_bonus.c get_next_line_utils_bonus.c create_stacks.c \
					ft_atoi.c utils_three.c utils_two.c utils.c valid_line_bonus.c big_sort.c find_best_elem.c\
					sort_to_three_a.c sort_checker_bonus.c util_bonus.c utils_two_bonus.c final_sort.c

HEADERS		= headers

CFLAGS		= -Wall -Wextra -Werror

CC			= gcc

OBJS 		= $(SRC_NAME:.c=.o)

OBJS_B 		= $(SRC_B:.c=.o)

%.o:		%.c $(HEADERS)/*.h
			$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS) Makefile
				$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

bonus:		$(NAME_B)

$(NAME_B):	$(OBJS_B) Makefile
				$(CC) $(CFLAGS) $(OBJS_B) -o $(NAME_B)

clean:
			rm -f $(OBJS)
			rm -f $(OBJS_B)

fclean:		clean
			rm -f $(NAME)
			rm -f $(NAME_B)

re:			fclean all

.PHONY:		all clean fclean bonus re