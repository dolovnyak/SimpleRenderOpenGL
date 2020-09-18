#include "libft.h"
#include "libjtoc.h"

int		pfg_log_error(const char *p, int id)
{
	ft_printf("ERROR: %d, %s\n", id, p);
	return (id);
}

int		pfg_is_num(enum e_type type)
{
	return (type == fractional || type == integer);
}