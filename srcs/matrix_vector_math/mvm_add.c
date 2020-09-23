#include "opengl_simple_render.h"

t_vec3	mvm_add_v3_v3(t_vec3 vec1, t_vec3 vec2)
{
	vec1.x += vec2.x;
	vec1.y += vec2.y;
	vec1.z += vec2.z;

	return vec1;
}