#include "opengl_simple_render.h"

void	move_object(t_glsr_main *main, t_object *object)
{
	if (glfwGetKey(main->window, GLFW_KEY_LEFT_ALT))
		return;
	if (glfwGetKey(main->window, GLFW_KEY_LEFT_SHIFT) && glfwGetKey(main->window, GLFW_KEY_UP))
		object->world_model = mvm_translate(object->world_model, (t_vec3){0.f, 0.f, -0.1f});
	else if (glfwGetKey(main->window, GLFW_KEY_UP))
		object->world_model = mvm_translate(object->world_model, (t_vec3){0.f, 0.1f, 0.f});
	if (glfwGetKey(main->window, GLFW_KEY_LEFT_SHIFT) && glfwGetKey(main->window, GLFW_KEY_DOWN))
		object->world_model = mvm_translate(object->world_model, (t_vec3){0.f, 0.f, 0.1f});
	else if (glfwGetKey(main->window, GLFW_KEY_DOWN))
		object->world_model = mvm_translate(object->world_model, (t_vec3){0.f, -0.1f, 0.f});
	if (glfwGetKey(main->window, GLFW_KEY_RIGHT))
		object->world_model = mvm_translate(object->world_model, (t_vec3){0.1f, 0.f, 0.f});
	if (glfwGetKey(main->window, GLFW_KEY_LEFT))
		object->world_model = mvm_translate(object->world_model, (t_vec3){-0.1f, 0.f, 0.f});
}

void	rotate_object(t_glsr_main *main, t_object *object)
{
	if (!glfwGetKey(main->window, GLFW_KEY_LEFT_ALT))
		return;
	if (glfwGetKey(main->window, GLFW_KEY_LEFT_SHIFT) && glfwGetKey(main->window, GLFW_KEY_UP))
		object->world_model = mvm_translate(object->world_model, (t_vec3){0.f, 0.f, -0.1f});
	else if (glfwGetKey(main->window, GLFW_KEY_UP))
		object->transform = mvm_x_rotate(object->transform, -ANGLE_X_SPEED);
	if (glfwGetKey(main->window, GLFW_KEY_LEFT_SHIFT) && glfwGetKey(main->window, GLFW_KEY_DOWN))
		object->world_model = mvm_translate(object->world_model, (t_vec3){0.f, 0.f, 0.1f});
	else if (glfwGetKey(main->window, GLFW_KEY_DOWN))
		object->transform = mvm_x_rotate(object->transform, ANGLE_X_SPEED);
	if (glfwGetKey(main->window, GLFW_KEY_RIGHT))
		object->transform = mvm_y_rotate(object->transform, ANGLE_Y_SPEED);
	if (glfwGetKey(main->window, GLFW_KEY_LEFT))
		object->transform = mvm_y_rotate(object->transform, -ANGLE_Y_SPEED);
}

void	objects_events_processing(t_glsr_main *main, t_scene *scene)
{
	if (glfwGetKey(main->window, GLFW_KEY_COMMA) && !main->previous_keys_map[GLFW_KEY_COMMA])
	{
		if (scene->cur_object_index == 0)
			scene->cur_object_index = scene->objects_num - 1;
		else
			scene->cur_object_index--;
	}
	else if (glfwGetKey(main->window, GLFW_KEY_PERIOD) && !main->previous_keys_map[GLFW_KEY_PERIOD])
	{
		if (scene->cur_object_index == scene->objects_num - 1)
			scene->cur_object_index = 0;
		else
			scene->cur_object_index++;
	}
	move_object(main, &scene->objects[scene->cur_object_index]);
	rotate_object(main, &scene->objects[scene->cur_object_index]);
}