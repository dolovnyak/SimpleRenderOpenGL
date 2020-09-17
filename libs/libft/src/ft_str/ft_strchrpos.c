#include "libft.h"

size_t	ft_strchrpos(char *s, int c)
{
	int i;

	i = -1;
	if (!s)
		return (0);
	while (s[++i])
		if (s[i] == (char)c)
			return (++i);
	return (0);
}
