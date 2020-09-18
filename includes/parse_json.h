#ifndef PARSE_JSON_H
#define PARSE_JSON_H

#include "libjtoc.h"

typedef struct		s_raw_camera
{

}					t_raw_camera;

typedef struct		s_raw_object
{
	char			*vertex_path;
	char			*fragment_path;
	char			*model_path;
	char			*material_path;
}					t_raw_object;

typedef struct		s_raw_scene
{
	t_raw_camera	raw_camera;
	t_raw_object	*raw_objects;
	int				objects_num;
}					t_raw_scene;

typedef struct		s_raw_main
{
	int				win_w;
	int				win_h;
	char			*win_title;
	t_raw_scene		*raw_scenes;
	int				scenes_num;
}					t_raw_main;

int			pfg_parse_main(t_raw_main *main, const char *path);
int			pfg_parse_window(t_raw_main *main, t_jnode *win_node);
int			pfg_parse_scenes(t_raw_main *main, t_jnode *scenes_node);
int			pfg_parse_scene_objects(t_raw_scene *scene, t_jnode *objs_node);
int			pfg_log_error(const char *p, int id);
int			pfg_is_num(enum e_type type);
#endif
