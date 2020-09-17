#include "matrix_vector_math.h"

t_mat1x4	mvm_get_m4_row(t_mat4 m, int row)
{
	if (row == 1)
		return (t_mat1x4){m.v1.x, m.v2.x, m.v3.x, m.v4.x};
	if (row == 2)
		return (t_mat1x4){m.v1.y, m.v2.y, m.v3.y, m.v4.y};
	if (row == 3)
		return (t_mat1x4){m.v1.z, m.v2.z, m.v3.z, m.v4.z};
	if (row == 4)
		return (t_mat1x4){m.v1.w, m.v2.w, m.v3.w, m.v4.w};
	return (t_mat1x4){-1.f, -1.f, -1.f, -1.f};
}

float		mvm_to_radians(float angle)
{
	return angle * (float)M_PI / 180.0f;
}