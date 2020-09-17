#include "matrix_vector_math.h"

t_mat4	mvm_translate(t_mat4 transform, t_vec3 vec)
{
	t_mat4 new_matrix;

	new_matrix = mvm_identity_m4x4();
	new_matrix.v4.x = vec.x;
	new_matrix.v4.y = vec.y;
	new_matrix.v4.z = vec.z;
	return mvm_multiply_m4_m4(transform, new_matrix);
}
