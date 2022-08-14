#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4000
# endif

# include <stdlib.h>
# include <unistd.h>

size_t	ft_strlen(const char *s);
char	*str_join(char *str1, char *str2);
char	*get_remain(char *str);
char	*get_line(char *str);
int		is_read(char *str);
char	*get_next_line(int fd);
#endif
