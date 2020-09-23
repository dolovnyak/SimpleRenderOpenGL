#include "opengl_simple_render.h"

static void	render_flags_processing(t_scene *scene, GLFWwindow *win, int w, int h)
{
	if (glfwGetKey(win, GLFW_KEY_P) == GLFW_PRESS)
	{
		scene->projection_type = GLSR_PERSPECTIVE;
		scene->projection = mvm_perspective(66.f, (float)w / (float)h, 0.1f, 1000.f);
	}
	else if (glfwGetKey(win, GLFW_KEY_O))
	{
		scene->projection_type = GLSR_ORTHOGRAPHIC;
		scene->projection = mvm_identity_m4x4();
	}
	if (glfwGetKey(win, GLFW_KEY_1) == GLFW_PRESS)
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	if (glfwGetKey(win, GLFW_KEY_2) == GLFW_PRESS)
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	if (glfwGetKey(win, GLFW_KEY_3) == GLFW_PRESS)
		glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);
}

void	events_processing(t_glsr_main *main, t_scene *scene, int w, int h)
{
	glfwPollEvents();
	if (glfwGetKey(main->window, GLFW_KEY_ESCAPE))
		glfwSetWindowShouldClose(main->window, GL_TRUE);
	render_flags_processing(scene, main->window, w, h);
	objects_events_processing(main, scene);
	if (glfwGetKey(main->window, GLFW_KEY_C) && !main->previous_keys_map[GLFW_KEY_C])
		main->color_flag = !main->color_flag;
	if (glfwGetKey(main->window, GLFW_KEY_T) && !main->previous_keys_map[GLFW_KEY_T])
		main->flat_flag = !main->flat_flag;
	for (int i = 0; i < MAX_KEYS; i++)
		main->previous_keys_map[i] = glfwGetKey(main->window, i);
}
