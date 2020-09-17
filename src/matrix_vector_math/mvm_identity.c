#include "matrix_vector_math.h"

t_mat4	mvm_identity_m4x4()
{
	t_mat4	matrix;

	matrix.v1 = (t_vec4){1.f, 0.f, 0.f, 0.f};
	matrix.v2 = (t_vec4){0.f, 1.f, 0.f, 0.f};
	matrix.v3 = (t_vec4){0.f, 0.f, 1.f, 0.f};
	matrix.v4 = (t_vec4){0.f, 0.f, 0.f, 1.f};
	return matrix;
}
