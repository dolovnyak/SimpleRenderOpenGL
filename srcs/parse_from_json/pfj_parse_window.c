#include "parse_json.h"

int	pfj_parse_window(t_raw_main *m, struct cJSON *win_n)
{
	cJSON	*tmp;
	cJSON	*size_n;

	if (!(tmp = cJSON_GetObjectItemCaseSensitive(win_n, "title")) || !cJSON_IsString(tmp))
		return (ft_log_error("WIN TITLE ERROR", -1));
	m->win_title = ft_strdup(tmp->valuestring);
	if (!(size_n = cJSON_GetObjectItemCaseSensitive(win_n, "size")) || !cJSON_IsObject(size_n))
		return (ft_log_error("WINDOW SIZE ERROR", -1));
	if (!(tmp = cJSON_GetObjectItemCaseSensitive(size_n, "x")) || !cJSON_IsNumber(tmp))
		return (ft_log_error("WINDOW SIZE.X ERROR", -1));
	m->win_w = tmp->valueint;
	if (!(tmp = cJSON_GetObjectItemCaseSensitive(size_n, "y")) || !cJSON_IsNumber(tmp))
		return (ft_log_error("WINDOW SIZE.Y ERROR", -1));
	m->win_h = tmp->valueint;
	return (1);
}
