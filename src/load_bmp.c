#include "bmpheader.h"
#include "scop.h"

t_bmpheader	read_and_check_bmpheader(FILE *file, const char *filename)
{
	t_bmpheader	bmpheader;    // File header sizeof(BMPheader) = 56
	size_t		res;

	res = fread(&bmpheader, 1, sizeof(t_bmpheader), file);
	if (res != sizeof(t_bmpheader))
	{
		fclose(file);
		ft_exit_with_error((const char *[]){"BMP FILE HEADER: ", filename, " DOESN'T CORRECT"}, -1);
	}
	if (bmpheader.bfType != 0x4d42 && bmpheader.bfType != 0x4349 && bmpheader.bfType != 0x5450)
	{
		fclose(file);
		ft_exit_with_error((const char *[]){"BMP FILE HEADER: ", filename, " DOESN'T CORRECT"}, -1);
	}
	return bmpheader;
}

int			is_bmp_file_correct(FILE *file, t_bmpheader bmpheader)
{
	int file_size;

	file_size = ftell(file);
	fseek(file, 0, SEEK_END);
	fseek(file, sizeof(t_bmpheader), SEEK_SET);
	if (bmpheader.bfSize != file_size ||
		bmpheader.bfReserved != 0 ||
		bmpheader.biPlanes != 1 ||
		(bmpheader.biSize != 40 && bmpheader.biSize != 108 && bmpheader.biSize != 124) ||
		bmpheader.bfOffBits != 14 + bmpheader.biSize ||

		bmpheader.biWidth < 1 || bmpheader.biWidth > 10000 ||
		bmpheader.biHeight < 1 || bmpheader.biHeight > 10000 ||
		bmpheader.biBitCount != 24 ||    //only full color
		bmpheader.biCompression != 0     //only not compressed
		)
		return (0);
	return (1);
}

t_texture load_bmp(const char *filename)
{
	t_texture		texture;
	FILE			*file;
	t_bmpheader		bmpheader;
	size_t			res;
	int				mx3 = (3 * texture.width + 3) & (-4);    // Compute row width in file, including padding to 4-byte boundary
	unsigned char	*tmp_buf = ft_memalloc(mx3 * texture.height);

	file = fopen(filename, "rb");
	if (!file)
		ft_exit_with_error((const char *[])
		{"FILE PATH: ", filename, " DOESN'T CORRECT", NULL}, -1);
	bmpheader = read_and_check_bmpheader(file, filename);
	if (!is_bmp_file_correct(file, bmpheader))
	{
		fclose(file);
		ft_exit_with_error((const char *[])
		{"BMP FILE: ", filename, " DOESN'T CORRECT FORMAT", NULL}, -1);
	}

	texture.width = bmpheader.biWidth;
	texture.height = bmpheader.biHeight;
	res = fread(tmp_buf, 1, mx3 * texture.height, file);
	if ((int) res != mx3 * texture.height)
	{
		fclose(file);
		ft_exit_with_error((const char *[])
		{"BMP FILE: ", filename, " DOESN'T CORRECT", NULL}, -1);
	}
	fclose(file);
	return texture;

// выделим память для результата
//	v = new int[mx * my];

	// Перенос данных (не забудем про BGR->RGB)
//	unsigned char *ptr = (unsigned char *) v;
//	for (int y = my - 1; y >= 0; y--)
//	{
//		unsigned char *pRow = tmp_buf + mx3 * y;
//		for (int x = 0; x < mx; x++)
//		{
//			*ptr++ = *(pRow + 2);
//			*ptr++ = *(pRow + 1);
//			*ptr++ = *pRow;
//			pRow += 3;
//			ptr++;
//		}
//	}
//	delete[] tmp_buf;
//	return v;    // OK
}