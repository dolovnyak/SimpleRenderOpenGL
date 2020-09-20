#include "parse_json.h"

int	pfj_parse_window(t_raw_main *main, t_jnode *win_node)
{
	t_jnode	*tmp;

	if (!(tmp = jtoc_node_get_by_path(win_node, "title")) || tmp->type != string)
		return (ft_log_error("MISSING WIN TITLE", -1));
	main->win_title = ft_strdup(jtoc_get_string(tmp));
	if (!(tmp = jtoc_node_get_by_path(win_node, "size.x")) || tmp->type != integer)
		return (ft_log_error("WINDOW SIZE.X ERROR", -1));
	main->win_w = jtoc_get_int(tmp);
	if (!(tmp = jtoc_node_get_by_path(win_node, "size.y")) || tmp->type != integer)
		return (ft_log_error("WINDOW SIZE.Y ERROR", -1));
	main->win_h = jtoc_get_int(tmp);
	return (1);
}
