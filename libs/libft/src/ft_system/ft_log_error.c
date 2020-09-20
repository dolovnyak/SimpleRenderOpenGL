#include "libft.h"

int		ft_log_error(const char *error, int id)
{
	ft_printf("ERROR: %d, %s\n", id, error);
	return (id);
}
