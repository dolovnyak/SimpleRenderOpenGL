#include "opengl_simple_render.h"

static int	init_glfw_and_window(t_glsr_main *main, int w, int h, char *title)
{
	glfwInitHint(GLFW_COCOA_CHDIR_RESOURCES, GLFW_FALSE);
	if (glfwInit() == GLFW_FALSE)
		return (ft_log_error("FAILED INIT GLFW", -1));
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	main->window = glfwCreateWindow(w, h, title,NULL, NULL);
	if (main->window == NULL)
	{
		glfwTerminate();
		return (ft_log_error("FAILED TO CREATE GLFW WINDOW", -1));
	}
	glfwMakeContextCurrent(main->window);
	return (1);
}

static int	init_glew()
{
	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK)
		return (ft_log_error("FAILED INIT GLEW", -1));
	return (1);
}

static void	configure_gl_and_get_framebuffer_size(t_glsr_main *main)
{
	glfwGetFramebufferSize(main->window, &main->frame_buffer_w, &main->frame_buffer_h);
	glViewport(0, 0, main->frame_buffer_w, main->frame_buffer_h);
	glClearColor(0.09f, 0.08f, 0.15f, 1.f);
	glEnable(GL_DEPTH_TEST);
}

static int	init_scenes(t_glsr_main *main, t_raw_main *raw_main)
{
	if (!(main->scenes = (t_scene *)ft_memalloc(sizeof(t_scene) * raw_main->scenes_num)))
		return (ft_log_error("FAILED MALLOC", -1));
	main->scenes_num = raw_main->scenes_num;
	for (int i = 0; i < raw_main->scenes_num; i++)
	{
		if (!(main->scenes[i].objects = (t_object *)ft_memalloc(sizeof(t_object) * raw_main->scenes[i].objs_num)))
			return (ft_log_error("FAILED MALLOC", -1));
		main->scenes[i].objects_num = raw_main->scenes[i].objs_num;
		for (int j = 0; j < main->scenes[i].objects_num; j++)
			if (create_object_from_raw(&(main->scenes[i].objects[j]), &(raw_main->scenes[i].objs[j])) < 0)
				return (ft_log_error("FAILED CREATE OBJECT", -1));
		main->scenes[i].projection = mvm_perspective(
				66.f, (float)main->frame_buffer_w / (float)main->frame_buffer_h, 0.1f, 1000.f);
		main->scenes[i].projection_type = GLSR_PERSPECTIVE;
	}
	return (1);
}

int			init(t_glsr_main *main, const char *config_path)
{
	t_raw_main	raw_main;

	ft_bzero(&raw_main, sizeof(t_raw_main));
	if (pfj_parse_main(&raw_main, config_path) < 0)
		return (ft_log_error("FAILED PARSE JSON", -1));
	if (init_glfw_and_window(main, raw_main.win_w, raw_main.win_h, raw_main.win_title) < 0)
		return (ft_log_error("FAILED GLFW", -1));
	if (init_glew() < 0)
		return (ft_log_error("FAILED GLEW", -1));
	configure_gl_and_get_framebuffer_size(main);
	if (init_scenes(main, &raw_main) < 0)
		return (ft_log_error("FAILED INIT SCENES", -1));
	return (1);
}
