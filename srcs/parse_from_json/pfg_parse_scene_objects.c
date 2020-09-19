#include "parse_json.h"

int	get_objs_num(t_jnode	*objects_node)
{
	int	n;

	n = 0;
	objects_node = objects_node->down;
	while (objects_node)
	{
		n++;
		objects_node = objects_node->right;
	}
	return n;
}

int	parse_object(t_raw_object *obj, t_jnode *obj_node)
{
	t_jnode	*tmp;

	if (!(tmp = jtoc_node_get_by_path(obj_node, "vertex_shader_path")) || tmp->type != string)
		return (pfg_log_error("MISSING VERTEX SHADER PATH", -1));
	obj->vertex_path = ft_strdup(jtoc_get_string(tmp));
	if (!(tmp = jtoc_node_get_by_path(obj_node, "fragment_shader_path")) || tmp->type != string)
		return (pfg_log_error("MISSING FRAGMENT SHADER PATH", -1));
	obj->fragment_path = ft_strdup(jtoc_get_string(tmp));
	if (!(tmp = jtoc_node_get_by_path(obj_node, "model_path")) || tmp->type != string)
		return (pfg_log_error("MISSING MODEL SHADER PATH", -1));
	obj->model_path = ft_strdup(jtoc_get_string(tmp));
	if (!(tmp = jtoc_node_get_by_path(obj_node, "material_path")) || tmp->type != string)
		return (pfg_log_error("MISSING MATERIAL SHADER PATH", -1));
	obj->material_path = ft_strdup(jtoc_get_string(tmp));
	if (!(tmp = jtoc_node_get_by_path(obj_node, "position")) || tmp->type != object)
		return (pfg_log_error("MISSING POSITION", -1));
	if (pfg_parse_vec3(&(obj->pos), tmp) < 0)
		return (pfg_log_error("MISSING POSITION", -1));
	return (1);
}

int	pfg_parse_scene_objects(t_raw_scene *scene, t_jnode *objs_node)
{
	t_jnode		*tmp;
	int			objects_num;
	int			i;

	i = 0;
	if (!(objects_num = get_objs_num(objs_node)))
		return (pfg_log_error("OBJECTS NUM", -1));
	scene->objs = (t_raw_object *)ft_memalloc(sizeof(t_raw_object) * objects_num);
	scene->objs_num = objects_num;
	objs_node = objs_node->down;
	while(objs_node)
	{
		if (parse_object(&(scene->objs[i]), objs_node) < 0)
			return (pfg_log_error("OBJECT", -1));
		objs_node = objs_node->right;
		i++;
	}
	return (1);
}
