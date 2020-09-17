#include "matrix_vector_math.h"

t_mat4	mvm_scale(t_mat4 transform, t_vec3 vec)
{
	t_mat4 scale_matrix;

	scale_matrix = mvm_identity_m4x4();
	scale_matrix.v1.x = vec.x;
	scale_matrix.v2.y = vec.y;
	scale_matrix.v3.z = vec.z;

	return mvm_multiply_m4_m4(transform, scale_matrix);
}
