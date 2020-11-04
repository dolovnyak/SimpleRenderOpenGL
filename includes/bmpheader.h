/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmpheader.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 22:06:32 by sbecker           #+#    #+#             */
/*   Updated: 2020/10/29 22:08:11 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BMPHEADER_H
# define BMPHEADER_H

# include <stdint.h>
# include "libft.h"

typedef struct		s_bmpheader
{
	uint16_t		file_type;
	unsigned int	file_size;
	unsigned int	reserved;
	unsigned int	offset_bits;
	int				info_header_size;
	int				width;
	int				height;
	u_int16_t		planes;
	u_int16_t		bit_per_pixel;
	unsigned int	compression;
	unsigned int	image_size;
	unsigned int	x_pixels_per_meter;
	unsigned int	y_pixels_per_meter;
	unsigned int	used_color;
	unsigned int	color_important;
}					t_bmpheader;

#endif
