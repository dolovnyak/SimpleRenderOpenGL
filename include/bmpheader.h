#ifndef BPM_HEADER_H
#define BPM_HEADER_H

#include <stdint.h>
#include <stdio.h>
#include "libft.h"

typedef struct	s_bmpheader
{
	uint16_t	bfType;				// 0x4d42 | 0x4349 | 0x5450
	int			bfSize;				// размер файла
	int			bfReserved;			// 0
	int			bfOffBits;			// смещение до поля данных, обычно 54 = 16 + biSize
	int			biSize;				// размер струкуры в байтах: 40(BITMAPINFOHEADER) или 108(BITMAPV4HEADER) или 124(BITMAPV5HEADER)
	int			biWidth;			// ширина в точках
	int			biHeight;			// высота в точках
	u_int16_t	biPlanes;			// всегда должно быть 1
	u_int16_t	biBitCount;			// 0 | 1 | 4 | 8 | 16 | 24 | 32
	int			biCompression;		// BI_RGB | BI_RLE8 | BI_RLE4 | BI_BITFIELDS | BI_JPEG | BI_PNG (реально используется лишь BI_RGB)
	int			biSizeImage;		// Количество байт в поле данных (обычно устанавливается в 0)
	int			biXPelsPerMeter;	// горизонтальное разрешение, точек на дюйм
	int			biYPelsPerMeter;	// вертикальное разрешение, точек на дюйм
	int			biClrUsed;			// Количество используемых цветов (если есть таблица цветов)
	int			biClrImportant;		// Количество существенных цветов (можно считать, просто 0)
}				t_bmpheader;

#endif
