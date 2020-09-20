#include "libft.h"

int	ft_vector_push_back(t_vector *vector, void *elem_data)
{
	if (!elem_data)
		return (-1);
	if (vector->size == 0)
	{
		if (!(vector->elems_data = malloc(vector->elem_size)))
			return (-1);
		ft_memcpy(vector->elems_data, elem_data, vector->elem_size);
		vector->size++;
	}
	else
	{
		vector->size++;
		if (!(vector->elems_data = realloc(vector->elems_data, (vector->size) * vector->elem_size)))
			return (-1);
		ft_memcpy(vector->elems_data + (vector->size - 1) * vector->elem_size,
			elem_data, vector->elem_size);
	}
	return (1);
}
