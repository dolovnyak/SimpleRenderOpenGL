#include "opengl_simple_render.h"

static int	init_glfw_and_window(t_glsr_main *main, int w, int h, char *title)
{
	glfwInitHint(GLFW_COCOA_CHDIR_RESOURCES, GLFW_FALSE);
	if (glfwInit() == GLFW_FALSE)
	{
		ft_printf("glfw init error\n");
		return (-1);
	}
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	main->window = glfwCreateWindow(w, h, title,NULL, NULL);
	if (main->window == NULL)
	{
		ft_printf("Failed to create GLFW window");
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(main->window);
	return (1);
}

static int	init_glew()
{
	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK)
	{
		ft_printf("glew init error\n");
		return (-1);
	}
	return (1);
}


static int	init_main_from_row(t_glsr_main *main, t_raw_main *raw_main)
{
	main->scenes = (t_scene *)ft_memalloc(sizeof(t_scene) * raw_main->scenes_num);
	main->scenes_num = raw_main->scenes_num;
	for (int i = 0; i < raw_main->scenes_num; i++)
	{
		main->scenes[i].objects = (t_object *)ft_memalloc(sizeof(t_object) * raw_main->scenes[i].objs_num);
		main->scenes[i].objects_num = raw_main->scenes[i].objs_num;
		for (int j = 0; j < main->scenes[i].objects_num; j++)
		{
			if (create_object_from_raw(&(main->scenes[i].objects[j]), &(raw_main->scenes[i].objs[j])) < 0)
				return (-1);
		}
	}
	return (1);
}

int			init(t_glsr_main *main, const char *config_path)
{
	t_raw_main	raw_main;

	if (pfg_parse_main(&raw_main, config_path) < 0)
		return (-1);
	if (init_glfw_and_window(main, raw_main.win_w, raw_main.win_h, raw_main.win_title) < 0)
		return (-1);
	if (init_glew() < 0)
		return (-1);
	if (init_main_from_row(main, &raw_main) < 0)
		return (-1);

	return (1);
}
