#include "libft.h"

t_vector	ft_vector_create(size_t	elem_size)
{
	t_vector	vector;

	vector.elem_size = elem_size;
	vector.size = 0;
	vector.elems_data = NULL;
	return vector;
}