#include "headers/get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*str_join(char *remain, char *buff)
{
	size_t	i;
	size_t	j;
	char	*str;

	i = -1;
	j = 0;
	if (!remain)
	{
		remain = (char *)malloc(1 * sizeof(char));
		remain[0] = '\0';
	}
	if (!remain || !buff)
		return (0);
	str = malloc(sizeof(char) * ((ft_strlen(remain) + ft_strlen(buff)) + 1));
	if (!str)
		return (0);
	if (remain)
		while (remain[++i])
			str[i] = remain[i];
	while (buff[j])
		str[i++] = buff[j++];
	str[ft_strlen(remain) + ft_strlen(buff)] = '\0';
	free(remain);
	return (str);
}
