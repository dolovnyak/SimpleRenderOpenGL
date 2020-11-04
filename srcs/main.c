#include <math.h>
#include "opengl_simple_render.h"

void	free_main(t_glsr_main	*main)
{
	for (int i = 0; i < main->scenes_num; i++)
		free(main->scenes[i].objects);
	free(main->scenes);
	ft_bzero(main, sizeof(t_glsr_main));
}

int		main(int argc, char **argv)
{
	t_glsr_main	m;

	if (argc != 2)
		return (ft_log_error("input json file path as argument", -1));
	if (init(&m, argv[1]) < 0)
	{
		SDL_Quit();
		ft_exit_with_error((const char *[]){"FAILED INIT", NULL}, -1);
	}
	render_loop(&m);
	free_main(&m);
	SDL_Quit();
	exit(EXIT_SUCCESS);
}
