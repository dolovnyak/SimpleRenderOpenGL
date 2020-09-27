#include <math.h>
#include "opengl_simple_render.h"


int main(int argc, char **argv)
{
	t_glsr_main	m;

	if (argc != 2)
		return (ft_log_error("input json file in argument", -1));
	if (init(&m, argv[1]) < 0)
	{
		SDL_Quit();
		ft_exit_with_error((const char *[]){"FAILED INIT", NULL}, -1);
	}
	render_loop(&m);
	SDL_Quit();
	exit(EXIT_SUCCESS);
}
