#include "opengl_simple_render.h"

int		vector_get_vec3_by_index(t_vec3 *vec, t_vector vector, size_t index)
{
	if (sizeof(t_vec3) != vector.elem_size)
		return (-1);
	if (index >= vector.size)
		return (-1);
	ft_memcpy(vec, vector.elems_data + vector.elem_size * index, vector.elem_size);
	return (1);
}

int		vector_get_vec2_by_index(t_vec2 *vec, t_vector vector, size_t index)
{
	if (sizeof(t_vec2) != vector.elem_size)
		return (-1);
	if (index >= vector.size)
		return (-1);
	ft_memcpy(vec, vector.elems_data + vector.elem_size * index, vector.elem_size);
	return (1);
}

int		vector_get_unsigned_by_index(unsigned *value, t_vector vector, size_t index)
{
	if (sizeof(unsigned) != vector.elem_size)
		return (-1);
	if (index >= vector.size)
		return (-1);
	ft_memcpy(value, vector.elems_data + vector.elem_size * index, vector.elem_size);
	return (1);
}
