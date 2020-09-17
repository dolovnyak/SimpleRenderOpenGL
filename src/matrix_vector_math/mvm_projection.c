#include "matrix_vector_math.h"

t_mat4  mvm_perspective(float fov_y, float aspect, float near_z, float far_z)
{
	float w, h;
	float right, top;

	fov_y = (fov_y / 2.f) * (float)M_PI / 180.f;

	h = tanf(fov_y) * 2.f * near_z;
	w = h * aspect;

	right = w / 2.f;
	top = h / 2.f;

	t_mat4 matrix;
	ft_bzero(&matrix, sizeof(t_mat4));

	matrix.v1.x = near_z / right;
	matrix.v2.y = near_z / top;
	matrix.v3.z = -(far_z + near_z) / (far_z - near_z);
	matrix.v4.z = -2.f * far_z * near_z / (far_z - near_z);
	matrix.v3.w = -1.f;

	return matrix;
}


