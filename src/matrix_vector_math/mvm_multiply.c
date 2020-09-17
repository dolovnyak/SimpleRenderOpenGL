#include "matrix_vector_math.h"

t_mat4	mvm_multiply_m4_m4(t_mat4 m1, t_mat4 m2)
{
	t_mat4		new_matrix;
	t_mat1x4	cur_row;

	cur_row = mvm_get_m4_row(m1, 1);
	new_matrix.v1.x = mvm_multiply_m1x4_v4(cur_row, m2.v1);
	new_matrix.v2.x = mvm_multiply_m1x4_v4(cur_row, m2.v2);
	new_matrix.v3.x = mvm_multiply_m1x4_v4(cur_row, m2.v3);
	new_matrix.v4.x = mvm_multiply_m1x4_v4(cur_row, m2.v4);

	cur_row = mvm_get_m4_row(m1, 2);
	new_matrix.v1.y = mvm_multiply_m1x4_v4(cur_row, m2.v1);
	new_matrix.v2.y = mvm_multiply_m1x4_v4(cur_row, m2.v2);
	new_matrix.v3.y = mvm_multiply_m1x4_v4(cur_row, m2.v3);
	new_matrix.v4.y = mvm_multiply_m1x4_v4(cur_row, m2.v4);

	cur_row = mvm_get_m4_row(m1, 3);
	new_matrix.v1.z = mvm_multiply_m1x4_v4(cur_row, m2.v1);
	new_matrix.v2.z = mvm_multiply_m1x4_v4(cur_row, m2.v2);
	new_matrix.v3.z = mvm_multiply_m1x4_v4(cur_row, m2.v3);
	new_matrix.v4.z = mvm_multiply_m1x4_v4(cur_row, m2.v4);

	cur_row = mvm_get_m4_row(m1, 4);
	new_matrix.v1.w = mvm_multiply_m1x4_v4(cur_row, m2.v1);
	new_matrix.v2.w = mvm_multiply_m1x4_v4(cur_row, m2.v2);
	new_matrix.v3.w = mvm_multiply_m1x4_v4(cur_row, m2.v3);
	new_matrix.v4.w = mvm_multiply_m1x4_v4(cur_row, m2.v4);
	return new_matrix;
}

float	mvm_multiply_m1x4_v4(t_mat1x4 m, t_vec4 v)
{
	return m.a1 * v.x + m.a2 * v.y + m.a3 * v.z + m.a4 * v.w;
}
