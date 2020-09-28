#include "opengl_simple_render.h"

static int	init_glew_gl()
{
	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK)
	{
		printf("GLEW: %s\n", glewGetErrorString(glewInit()));
		return (ft_log_error("FAILED INIT GLEW", -1));
	}
	glClearColor(0.09f, 0.08f, 0.15f, 1.f);
	glEnable(GL_DEPTH_TEST);
	return (1);
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
				66.f, (float)main->win_w / (float)main->win_h, 0.1f, 100.f);
		main->scenes[i].projection_type = GLSR_PERSPECTIVE;
	}
	return (1);
}

void		free_raw_main(t_raw_main *raw_main)
{
	t_raw_scene scene;

	free(raw_main->win_title);
	for (int i = 0; i < raw_main->scenes_num; i++)
	{
		scene = raw_main->scenes[i];
		for (int j = 0; j < scene.objs_num; j++)
		{
			free(scene.objs[j].model_path);
			free(scene.objs[j].material_path);
			free(scene.objs[j].fragment_path);
			free(scene.objs[j].vertex_path);
		}
		free(scene.objs);
	}
	free(raw_main->scenes);
	ft_bzero(raw_main, sizeof(t_raw_main));
}

int			init_sdl(t_glsr_main *main, t_raw_main *raw_main)
{
	int error;

	error = SDL_Init(SDL_INIT_VIDEO);
	if (error < 0)
		return (ft_log_error("failed sdl init", -1));
	SDL_GL_SetAttribute( SDL_GL_CONTEXT_MAJOR_VERSION, 4 );
	SDL_GL_SetAttribute( SDL_GL_CONTEXT_MINOR_VERSION, 1 );
	SDL_GL_SetAttribute( SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE );
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, SDL_TRUE);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 32);
	SDL_GL_SetSwapInterval(1);
	main->window = SDL_CreateWindow(raw_main->win_title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
							raw_main->win_w, raw_main->win_h, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN | SDL_WINDOW_ALLOW_HIGHDPI);
	if (main->window == NULL)
		return (ft_log_error("failed init window", -1));
	main->cur_keys_map = SDL_GetKeyboardState(NULL);
	SDL_GetWindowSize(main->window, &main->win_w, &main->win_h);
	SDL_GL_CreateContext(main->window);
	return (1);
}

int			init(t_glsr_main *main, const char *config_path)
{
	t_raw_main	raw_main;

	ft_bzero(main, sizeof(t_glsr_main));
	ft_bzero(&raw_main, sizeof(t_raw_main));
	if (pfj_parse_main(&raw_main, config_path) < 0)
		return (ft_log_error("FAILED PARSE JSON", -1));
	if (init_sdl(main, &raw_main) < 0)
		return (ft_log_error("FAILED SDL", -1));
	if (init_glew_gl() < 0)
		return (ft_log_error("FAILED GLEW", -1));
	if (init_scenes(main, &raw_main) < 0)
		return (ft_log_error("FAILED INIT SCENES", -1));
	free_raw_main(&raw_main);
	return (1);
}
