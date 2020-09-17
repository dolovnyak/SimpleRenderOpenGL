#ifndef BPM_HEADER_H
#define BPM_HEADER_H

#include <stdint.h>
#include "libft.h"

typedef struct		s_bmpheader
{
	uint16_t		file_type;				// 0x4d42 | 0x4349 | 0x5450
	unsigned int	file_size;				// размер файла
	unsigned int	reserved;			// 0
	unsigned int	offset_bits;			// смещение до поля данных, обычно 54 = 16 + biSize
	int				info_header_size;				// размер струкуры в байтах: 40(BITMAPINFOHEADER) или 108(BITMAPV4HEADER) или 124(BITMAPV5HEADER)
	int				width;			// ширина в точках
	int				height;			// высота в точках
	u_int16_t		planes;			// всегда должно быть 1
	u_int16_t		bit_per_pixel;			// 0 | 1 | 4 | 8 | 16 | 24 | 32
	unsigned int	compression;		// BI_RGB | BI_RLE8 | BI_RLE4 | BI_BITFIELDS | BI_JPEG | BI_PNG (реально используется лишь BI_RGB)
	unsigned int	image_size;		// Количество байт в поле данных (обычно устанавливается в 0)
	unsigned int	x_pixels_per_meter;	// горизонтальное разрешение, точек на дюйм
	unsigned int	y_pixels_per_meter;	// вертикальное разрешение, точек на дюйм
	unsigned int	used_color;			// Количество используемых цветов (если есть таблица цветов)
	unsigned int	color_important;		// Количество существенных цветов (можно считать, просто 0)
}					t_bmpheader;

#endif
