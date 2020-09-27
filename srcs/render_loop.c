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
	t_mat4		view;

	view = mvm_identity_m4x4();
	objs = scene->objects;
	objs_num = scene->objects_num;
	for (int i = 0; i < objs_num; i++)
	{
		view = mvm_translate(view, (t_vec3){0.f, 0.f, -3.f});
//		render_object(&(objs[i]), &scene->camera.view, &scene->projection);
		render_object(main, &(objs[i]), &view, &scene->projection);
	}
}

void	render_loop(t_glsr_main *m)
{
	SDL_Event	e;

	while(!(m->params & QUIT_PROGRAM))
	{
		if (SDL_PollEvent(&e))
			if ((e.type == SDL_KEYDOWN && e.key.keysym.scancode == SDL_SCANCODE_ESCAPE) || e.type == SDL_QUIT)
				m->params |= QUIT_PROGRAM;
		events_processing(m);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glViewport(0, 0, m->win_w, m->win_h);
		render_scene(m, &(m->scenes[0]));
		glUseProgram(0);
		glBindVertexArray(0);
		SDL_GL_SwapWindow(m->window);
	}
}
