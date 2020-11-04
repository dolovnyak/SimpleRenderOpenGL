/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_json.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 22:09:38 by sbecker           #+#    #+#             */
/*   Updated: 2020/10/29 22:10:06 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_JSON_H
# define PARSE_JSON_H

# include "cJSON.h"
# include "matrix_vector_math.h"

typedef struct		s_raw_camera
{
	t_vec3			pos;
}					t_raw_camera;

typedef struct		s_raw_object
{
	char			*vertex_path;
	char			*fragment_path;
	char			*model_path;
	char			*material_path;
	t_vec3			pos;
}					t_raw_object;

typedef struct		s_raw_scene
{
	t_raw_camera	camera;
	t_raw_object	*objs;
	int				objs_num;
}					t_raw_scene;

typedef struct		s_raw_main
{
	int				win_w;
	int				win_h;
	char			*win_title;
	t_raw_scene		*scenes;
	int				scenes_num;
}					t_raw_main;

int					pfj_parse_main(t_raw_main *m, const char *path);
int					pfj_parse_window(t_raw_main *m, cJSON *win_n);
int					pfj_parse_scenes(t_raw_main *m, cJSON *scenes_n);
int					pfj_parse_scene_objects(t_raw_scene *scene, cJSON *objs_n);
int					pfj_parse_vec3(t_vec3 *vec, cJSON *vec_n);
#endif
