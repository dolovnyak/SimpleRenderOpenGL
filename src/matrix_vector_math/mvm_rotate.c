#include "matrix_vector_math.h"

t_mat4	mvm_x_rotate(t_mat4 transform, float angle)
{
	t_mat4	new_transform = mvm_identity_m4x4();
	float	radian_angle = mvm_to_radians(angle);
	float	cos_angle = cosf(radian_angle);
	float	sin_angle = sinf(radian_angle);

	new_transform.v2.y = cos_angle;
	new_transform.v2.z = sin_angle;
	new_transform.v3.y = -sin_angle;
	new_transform.v3.z = cos_angle;
	return mvm_multiply_m4_m4(transform, new_transform);
}

t_mat4	mvm_y_rotate(t_mat4 transform, float angle)
{
	t_mat4	new_transform = mvm_identity_m4x4();
	float	radian_angle = mvm_to_radians(angle);
	float	cos_angle = cosf(radian_angle);
	float	sin_angle = sinf(radian_angle);

	new_transform.v1.x = cos_angle;
	new_transform.v1.z = -sin_angle;
	new_transform.v3.x = sin_angle;
	new_transform.v3.z = cos_angle;
	return mvm_multiply_m4_m4(transform, new_transform);
}

t_mat4	mvm_z_rotate(t_mat4 transform, float angle)
{
	t_mat4	new_transform = mvm_identity_m4x4();
	float	radian_angle = mvm_to_radians(angle);
	float	cos_angle = cosf(radian_angle);
	float	sin_angle = sinf(radian_angle);

	new_transform.v1.x = cos_angle;
	new_transform.v1.y = sin_angle;
	new_transform.v2.x = -sin_angle;
	new_transform.v2.y = cos_angle;
	return mvm_multiply_m4_m4(transform, new_transform);
}
