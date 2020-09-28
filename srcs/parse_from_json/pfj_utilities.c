#include "parse_json.h"

int		pfj_parse_vec3(t_vec3 *vec, cJSON *vec_n)
{
	cJSON	*tmp;

	if (!(tmp = cJSON_GetObjectItemCaseSensitive(vec_n, "x")) || !cJSON_IsNumber(tmp))
		return (ft_log_error("X", -1));
	vec->x = (float)tmp->valuedouble;
	if (!(tmp = cJSON_GetObjectItemCaseSensitive(vec_n, "y")) || !cJSON_IsNumber(tmp))
		return (ft_log_error("Y", -1));
	vec->y = (float)tmp->valuedouble;
	if (!(tmp = cJSON_GetObjectItemCaseSensitive(vec_n, "z")) || !cJSON_IsNumber(tmp))
		return (ft_log_error("Z", -1));
	vec->z = (float)tmp->valuedouble;
	return (1);
}
