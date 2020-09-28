#include "parse_json.h"

int	get_objs_num(cJSON	*objs_n)
{
	cJSON	*obj_n;
	int		n;

	n = 0;
	cJSON_ArrayForEach(obj_n, objs_n)
		n++;
	return n;
}

int	parse_object(t_raw_object *obj, cJSON *obj_n)
{
	cJSON	*tmp;

	if (!(tmp = cJSON_GetObjectItemCaseSensitive(obj_n, "vertex_shader_path")) || !cJSON_IsString(tmp))
		return (ft_log_error("VERTEX SHADER PATH", -1));
	obj->vertex_path = ft_strdup(tmp->valuestring);
	if (!(tmp = cJSON_GetObjectItemCaseSensitive(obj_n, "fragment_shader_path")) || !cJSON_IsString(tmp))
		return (ft_log_error("FRAGMENT SHADER PATH", -1));
	obj->fragment_path = ft_strdup(tmp->valuestring);
	if (!(tmp = cJSON_GetObjectItemCaseSensitive(obj_n, "model_path")) || !cJSON_IsString(tmp))
		return (ft_log_error("MODEL PATH", -1));
	obj->model_path = ft_strdup(tmp->valuestring);
	if (!(tmp = cJSON_GetObjectItemCaseSensitive(obj_n, "material_path")) || !cJSON_IsString(tmp))
		return (ft_log_error("MATERIAL PATH", -1));
	obj->material_path = ft_strdup(tmp->valuestring);
	if (!(tmp = cJSON_GetObjectItemCaseSensitive(obj_n, "position")) || !cJSON_IsObject(tmp))
		return (ft_log_error("POSITION", -1));
	if (pfj_parse_vec3(&(obj->pos), tmp) < 0)
		return (ft_log_error("POSITION", -1));
	return (1);
}

int	pfj_parse_scene_objects(t_raw_scene *scene, cJSON *objs_n)
{
	cJSON		*obj_n;
	int			objects_num;
	int			i;

	i = 0;
	if (!(objects_num = get_objs_num(objs_n)))
		return (ft_log_error("SCENE OBJECTS", -1));
	scene->objs = (t_raw_object *)ft_memalloc(sizeof(t_raw_object) * objects_num);
	scene->objs_num = objects_num;
	cJSON_ArrayForEach(obj_n, objs_n)
	{
		if (parse_object(&(scene->objs[i]), obj_n) < 0)
			return (ft_log_error("OBJECT", -1));
		i++;
	}
	return (1);
}
