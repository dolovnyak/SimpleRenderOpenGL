#include <math.h>
#include "opengl_simple_render.h"

void	render_object(t_glsr_main *main, t_object *obj, t_mat4 *view, t_mat4 *projection)
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
	glUniform1i(glGetUniformLocation(program_id, "colorFlag"), (GLint)main->color_flag);
	glUniform1i(glGetUniformLocation(program_id, "flatFlag"), (GLint)main->flat_flag);
	glBindTexture(GL_TEXTURE_2D, obj->render_model.texture_id);
	glBindVertexArray(obj->render_model.vao);
	glDrawArrays(GL_TRIANGLES, 0, obj->render_model.vertex_count);
	glBindVertexArray(0);
}

void	render_scene(t_glsr_main *main, t_scene *scene)
{
	t_object	*objs;
	int			objs_num;

	objs = scene->objects;
	objs_num = scene->objects_num;
	for (int i = 0; i < objs_num; i++)
	{
		t_mat4 view = mvm_identity_m4x4();
		view = mvm_translate(view, (t_vec3){0.f, 0.f, -3.f});
//		render_object(&(objs[i]), &scene->camera.view, &scene->projection);
		render_object(main, &(objs[i]), &view, &scene->projection);
	}
}


int main(int argc, char **argv)
{
	t_glsr_main	main;

	if (argc != 2)
		return (ft_log_error("input json file in argument", -1));
	ft_bzero(&main, sizeof(t_glsr_main));
	if (init(&main, argv[1]) < 0)
	{
		glfwTerminate();
		return ft_log_error("FAILED INIT", -1);
	}
	while(!glfwWindowShouldClose(main.window))
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		events_processing(&main, &(main.scenes[0]), main.frame_buffer_w, main.frame_buffer_h);
		render_scene(&main, &(main.scenes[0]));
		glfwSwapBuffers(main.window);
	}
	glfwDestroyWindow(main.window);
	glfwTerminate();
	return 0;
}
