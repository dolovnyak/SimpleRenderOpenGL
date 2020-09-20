#include "libft.h"

void ft_vector_free(t_vector *vector)
{
	if (vector->size == 0 || vector->elems_data == NULL)
		return;
	free(vector->elems_data);
	vector->elem_size = 0;
	vector->size = 0;
}
