#include "parse_json.h"

static int	get_scenes_num(cJSON *scenes_n)
{
	cJSON	*scene_n;
	int		n;

	n = 0;
	cJSON_ArrayForEach(scene_n, scenes_n)
		n++;
	return n;
}

int	pfj_parse_scenes(t_raw_main *m, cJSON *scenes_n)
{
	cJSON		*tmp;
	cJSON		*scene_n;
	int			scenes_num;
	int			i;

	i = 0;
	scenes_num = get_scenes_num(scenes_n);
	m->scenes = (t_raw_scene *)ft_memalloc(sizeof(t_raw_scene) * scenes_num);
	m->scenes_num = scenes_num;
	cJSON_ArrayForEach(scene_n, scenes_n)
	{
		if (!(tmp = cJSON_GetObjectItemCaseSensitive(scene_n, "objects")) || !cJSON_IsArray(tmp))
			return (ft_log_error("SCENE OBJECTS", -1));
		if (pfj_parse_scene_objects(&(m->scenes[i]), tmp) < 0)
			return (ft_log_error("PARSE SCENE OBJECTS", -1));
		i++;
	}
	return (1);
}
