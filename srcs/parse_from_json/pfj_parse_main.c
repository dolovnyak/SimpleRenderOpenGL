#include "parse_json.h"

int	pfj_parse_main(t_raw_main *m, const char *path)
{
	char	*json;
	cJSON	*root;
	cJSON	*tmp;

	if (ft_read_file(path, &json) < 0)
		return (ft_log_error("JSON FILE DOESN'T CORRECT", -1));
	if (!(root = cJSON_Parse(json)))
	{
		cJSON_Delete(root);
		return (ft_log_error(cJSON_GetErrorPtr(), -1));
	}
	if (!(tmp = cJSON_GetObjectItemCaseSensitive(root, "window")) && !cJSON_IsObject(tmp))
		return (ft_log_error("WINDOW SECTION", -1));
	if (pfj_parse_window(m, tmp) < 0)
		return (ft_log_error("PARSE WINDOW", -1));
	if (!(tmp = cJSON_GetObjectItemCaseSensitive(root, "scenes")) && !cJSON_IsArray(tmp))
		return (ft_log_error("SCENES SECTION", -1));
	if (pfj_parse_scenes(m, tmp) < 0)
		return (ft_log_error("PARSING SCENE", -1));
	cJSON_Delete(root);
	free(json);
	return (1);
}