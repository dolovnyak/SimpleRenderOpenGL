#include "parse_json.h"

static int	get_scenes_num(t_jnode *scenes_node)
{
	int	n;

	n = 0;
	scenes_node = scenes_node->down;
	while (scenes_node)
	{
		n++;
		scenes_node = scenes_node->right;
	}
	return n;
}

int	pfg_parse_scenes(t_raw_main *main, t_jnode *scenes_node)
{
	t_jnode		*tmp;
	int			scenes_num;
	int			i;

	i = 0;
	if (!(scenes_num = get_scenes_num(scenes_node)))
		return (pfg_log_error("SCENES", -1));
	main->raw_scenes = (t_raw_scene *)ft_memalloc(sizeof(t_raw_scene) * scenes_num);
	main->scenes_num = scenes_num;
	scenes_node = scenes_node->down;
	while (scenes_node)
	{
		if (!(tmp = jtoc_node_get_by_path(scenes_node, "objects")) || tmp->type != array)
			return (pfg_log_error("SCENE OBJECTS", -1));
		if (pfg_parse_scene_objects(&(main->raw_scenes[i]), tmp) < 0)
			return (pfg_log_error("SCENE OBJECTS", -1));
		i++;
		scenes_node = scenes_node->right;
	}
	return (1);
}
