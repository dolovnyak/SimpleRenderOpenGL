#include <math.h>
#include "opengl_simple_render.h"

void	render_object(t_object *obj, t_mat4 *view, t_mat4 *projection)
{
	GLuint	program_id;

	program_id = obj->shader_program_id;
	glUseProgram(program_id);
	glUniformMatrix4fv(glGetUniformLocation(program_id, "transform"), 1, GL_FALSE,
					(GLfloat*)&obj->transform);
	glUniformMatrix4fv(glGetUniformLocation(program_id, "view"), 1, GL_FALSE,
					(GLfloat*)view);
	glUniformMatrix4fv(glGetUniformLocation(program_id, "projection"), 1, GL_FALSE,
					(GLfloat*)projection);
	glUniformMatrix4fv(glGetUniformLocation(program_id, "model"), 1, GL_FALSE,
					(GLfloat*)&obj->world_model);
	glBindTexture(GL_TEXTURE_2D, obj->render_model.texture_id);
	glBindVertexArray(obj->render_model.vao);
	glDrawArrays(GL_TRIANGLES, 0, obj->render_model.vertex_count);
	glBindVertexArray(0);
}

void	render_scene(t_scene *scene)
{
	t_object	*objs;
	int			objs_num;

	objs = scene->objects;
	objs_num = scene->objects_num;
	for (int i = 0; i < objs_num; i++)
	{
//		render_object(&(objs[i]), &scene->camera.view, &scene->projection);
		t_mat4 view = mvm_identity_m4x4();
		view = mvm_translate(view, (t_vec3){0.f, 0.f, -3.f});
		render_object(&(objs[i]), &view, &scene->projection);
	}
}

void	events_processing(t_scene *scene, GLFWwindow *win, int w, int h)
{
	glfwPollEvents();

	if (glfwGetKey(win, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(win, GL_TRUE);
	if (glfwGetKey(win, GLFW_KEY_P) == GLFW_PRESS)
	{
		if (scene->projection_type == GLSR_PERSPECTIVE)
		{
			scene->projection_type = GLSR_ORTHOGRAPHIC;
			scene->projection = mvm_identity_m4x4();
		}
		else
		{
			scene->projection_type = GLSR_PERSPECTIVE;
			scene->projection = mvm_perspective(66.f, (float)w / (float)h, 0.1f, 100.f);
		}
	}
	if (glfwGetKey(win, GLFW_KEY_1) == GLFW_PRESS)
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	if (glfwGetKey(win, GLFW_KEY_2) == GLFW_PRESS)
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	if (glfwGetKey(win, GLFW_KEY_3) == GLFW_PRESS)
		glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);

	static float angle_x = 0.f;
	static float angle_y = 0.f;
	static float angle_z = 0.f;
	angle_x += 0.05f;
	angle_y += 0.05f;
	angle_z += 0.05f;

	for (int i = 0; i < scene->objects_num; i++)
	{
		scene->objects[i].transform = mvm_identity_m4x4();
		scene->objects[i].transform = mvm_x_rotate(scene->objects[i].transform, angle_x);
		scene->objects[i].transform = mvm_y_rotate(scene->objects[i].transform, angle_y);
		scene->objects[i].transform = mvm_z_rotate(scene->objects[i].transform, angle_z);
	}
}

int main()
{
	t_glsr_main	main;

	if (init(&main, "./jsons/config.json") == -1)
		return (-1);

	glfwGetFramebufferSize(main.window, &main.frame_buffer_w, &main.frame_buffer_h);
	glViewport(0, 0, main.frame_buffer_w, main.frame_buffer_h);
	glClearColor(0.09f, 0.08f, 0.15f, 1.f);

	t_mat4 model = mvm_identity_m4x4();
	model = mvm_x_rotate(model, -70.f);

	t_mat4 view = mvm_identity_m4x4();
	view = mvm_translate(view, (t_vec3){0.f, 0.f, -3.f});

	main.scenes[0].projection = mvm_perspective(66.f, (float)main.frame_buffer_w / (float)main.frame_buffer_h, 0.1f, 100.f);
	glEnable(GL_DEPTH_TEST);
	while(!glfwWindowShouldClose(main.window))
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		events_processing(&(main.scenes[0]), main.window, main.frame_buffer_w, main.frame_buffer_h);
		render_scene(&(main.scenes[0]));
		glfwSwapBuffers(main.window);
	}

	ft_printf("Hello, World!\n");
	glfwTerminate();
	return 0;
}
