#include "parse_json.h"

int	pfj_parse_main(t_raw_main *main, const char *path)
{
	t_jnode		*root;
	t_jnode		*tmp;

	if (!(root = jtoc_read(path)))
		return (ft_log_error("READ JSON", -1));
	if (!(tmp = jtoc_node_get_by_path(root, "window")) || tmp->type != object)
		return (ft_log_error("MISSING WINDOW SECTION", -1));
	if (pfj_parse_window(main, tmp) < 0)
		return (ft_log_error("PARSE WINDOW", -1));
	if (!(tmp = jtoc_node_get_by_path(root, "scenes")) || tmp->type != array)
		return (ft_log_error("MISSING SCENES SECTION", -1));
	if (pfj_parse_scenes(main, tmp) < 0)
		return (ft_log_error("PARSING SCENES", -1));
	jtoc_node_clear(root);
	return (1);
}