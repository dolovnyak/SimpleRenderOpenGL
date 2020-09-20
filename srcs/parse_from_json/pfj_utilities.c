#include <matrix_vector_math.h>
#include "libft.h"
#include "libjtoc.h"

int		pfj_parse_vec3(t_vec3 *vec, t_jnode *n)
{
	t_jnode	*tmp;

	if (!(tmp = jtoc_node_get_by_path(n, "x")) || tmp->type != fractional)
		return (ft_log_error("X", -1));
	vec->x = jtoc_get_float(tmp);
	if (!(tmp = jtoc_node_get_by_path(n, "y")) || tmp->type != fractional)
		return (ft_log_error("Y", -1));
	vec->y = jtoc_get_float(tmp);
	if (!(tmp = jtoc_node_get_by_path(n, "z")) || tmp->type != fractional)
		return (ft_log_error("Z", -1));
	vec->z = jtoc_get_float(tmp);
	return (1);
}
