#include "opengl_simple_render.h"

void	move_object(t_glsr_main *m, t_object *object)
{
	if (m->cur_keys_map[SDL_SCANCODE_LALT])
		return;
	if (m->cur_keys_map[SDL_SCANCODE_LSHIFT] && m->cur_keys_map[SDL_SCANCODE_UP])
		object->world_model = mvm_translate(object->world_model, (t_vec3){0.f, 0.f, -0.1f});
	else if (m->cur_keys_map[SDL_SCANCODE_UP])
		object->world_model = mvm_translate(object->world_model, (t_vec3){0.f, 0.1f, 0.f});
	if (m->cur_keys_map[SDL_SCANCODE_LSHIFT] && m->cur_keys_map[SDL_SCANCODE_DOWN])
		object->world_model = mvm_translate(object->world_model, (t_vec3){0.f, 0.f, 0.1f});
	else if (m->cur_keys_map[SDL_SCANCODE_DOWN])
		object->world_model = mvm_translate(object->world_model, (t_vec3){0.f, -0.1f, 0.f});
	if (m->cur_keys_map[SDL_SCANCODE_RIGHT])
		object->world_model = mvm_translate(object->world_model, (t_vec3){0.1f, 0.f, 0.f});
	if (m->cur_keys_map[SDL_SCANCODE_LEFT])
		object->world_model = mvm_translate(object->world_model, (t_vec3){-0.1f, 0.f, 0.f});
}

void	rotate_object(t_glsr_main *m, t_object *obj)
{
	if (!m->cur_keys_map[SDL_SCANCODE_LALT])
		return;
	if (m->cur_keys_map[SDL_SCANCODE_UP])
		obj->transform = mvm_x_rotate(obj->transform, -ANGLE_X_SPEED);
	if (m->cur_keys_map[SDL_SCANCODE_DOWN])
		obj->transform = mvm_x_rotate(obj->transform, ANGLE_X_SPEED);
	if (m->cur_keys_map[SDL_SCANCODE_RIGHT])
		obj->transform = mvm_y_rotate(obj->transform, ANGLE_Y_SPEED);
	if (m->cur_keys_map[SDL_SCANCODE_LEFT])
		obj->transform = mvm_y_rotate(obj->transform, -ANGLE_Y_SPEED);
}

void	objects_events_processing(t_glsr_main *m, t_scene *scene)
{
	if (m->cur_keys_map[SDL_SCANCODE_COMMA] && !m->previous_keys_map[SDL_SCANCODE_COMMA])
	{
		if (scene->cur_object_index == 0)
			scene->cur_object_index = scene->objects_num - 1;
		else
			scene->cur_object_index--;
	}
	if (m->cur_keys_map[SDL_SCANCODE_PERIOD] && !m->previous_keys_map[SDL_SCANCODE_PERIOD])
	{
		if (scene->cur_object_index == scene->objects_num - 1)
			scene->cur_object_index = 0;
		else
			scene->cur_object_index++;
	}
	move_object(m, &scene->objects[scene->cur_object_index]);
	rotate_object(m, &scene->objects[scene->cur_object_index]);
}

static void	render_flags_processing(t_glsr_main *m, t_scene *scene)
{
//	if (glfwGetKey(win, GLFW_KEY_P) == GLFW_PRESS)
//	{
//		scene->projection_type = GLSR_PERSPECTIVE;
//		scene->projection = mvm_perspective(66.f, (float)w / (float)h, 0.1f, 1000.f);
//	}
//	else if (glfwGetKey(win, GLFW_KEY_O))
//	{
//		scene->projection_type = GLSR_ORTHOGRAPHIC;
//		scene->projection = mvm_identity_m4x4();
//	}
	if (m->cur_keys_map[SDL_SCANCODE_1])
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	if (m->cur_keys_map[SDL_SCANCODE_2])
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	if (m->cur_keys_map[SDL_SCANCODE_3])
		glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);
	if (m->cur_keys_map[SDL_SCANCODE_C] && !m->previous_keys_map[SDL_SCANCODE_C])
		m->color_flag = !m->color_flag;
	if (m->cur_keys_map[SDL_SCANCODE_T] && !m->previous_keys_map[SDL_SCANCODE_T])
		m->flat_flag = !m->flat_flag;
}

void	events_processing(t_glsr_main *m)
{
	render_flags_processing(m, &m->scenes[0]);
	objects_events_processing(m, &m->scenes[0]);
	for (int i = 0; i < SDL_NUM_SCANCODES; i++)
		m->previous_keys_map[i] = m->cur_keys_map[i];
}
