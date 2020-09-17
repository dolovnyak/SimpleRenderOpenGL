#include <fcntl.h>
#include <stdio.h>
#include "bmpheader.h"
#include "scop.h"

t_bmpheader	read_and_check_bmpheader(FILE *file, const char *filename)
{
	t_bmpheader	bmpheader;
	size_t		res;

	fread(&bmpheader.file_type, 2, 1, file);
	fread(&bmpheader.file_size, 4, 1, file);
	fread(&bmpheader.reserved, 4, 1, file);
	fread(&bmpheader.offset_bits, 4, 1, file);
	fread(&bmpheader.info_header_size, 4, 1, file);
	fread(&bmpheader.width, 4, 1, file);
	fread(&bmpheader.height, 4, 1, file);
	fread(&bmpheader.planes, 2, 1, file);
	fread(&bmpheader.bit_per_pixel, 2, 1, file);
	fread(&bmpheader.compression, 4, 1, file);
	fread(&bmpheader.image_size, 4, 1, file);
	fread(&bmpheader.x_pixels_per_meter, 4, 1, file);
	fread(&bmpheader.y_pixels_per_meter, 4, 1, file);
	fread(&bmpheader.used_color, 4, 1, file);
	res = fread(&bmpheader.color_important, 4, 1, file);

	bmpheader.width = bmpheader.width < 0 ? -bmpheader.width : bmpheader.width;
	bmpheader.height = bmpheader.height < 0 ? -bmpheader.height : bmpheader.height;

//	fseek(file, 0, SEEK_END);
//	int file_size = ftell(file);
//
//	if (res == 0 ||
//	(bmpheader.file_type != 0x4d42 && bmpheader.file_type != 0x4349 && bmpheader.file_type != 0x5450) ||
//	bmpheader.file_size != file_size ||
//	bmpheader.reserved != 0 ||
//	bmpheader.planes != 1 ||
//	(bmpheader.info_header_size != 40 && bmpheader.info_header_size != 108 && bmpheader.info_header_size != 124) ||
//	bmpheader.bit_per_pixel != 24 ||    //only full color
//	bmpheader.compression != 0     //only not compressed
//		)
//	{
//		fclose(file);
//		ft_exit_with_error((const char *[]){"BMP FILE HEADER: ", filename, " DOESN'T CORRECT", NULL}, -1);
//	}

//	fclose(file);
	return bmpheader;
}

t_texture load_bmp(const char *filename)
{
	t_texture		texture;
	FILE			*file;
	t_bmpheader		bmpheader;
	size_t			res;


	file = fopen(filename, "rb");
	if (!file)
		ft_exit_with_error((const char *[])
								   {"FILE PATH: ", filename, " DOESN'T CORRECT", NULL}, -1);

	bmpheader = read_and_check_bmpheader(file, filename);


	bmpheader.image_size = bmpheader.width * bmpheader.height * (bmpheader.bit_per_pixel / 8);
	unsigned char *image = (unsigned char*)malloc(bmpheader.image_size + 1);
//	rewind(file);
	fseek(file, bmpheader.offset_bits, SEEK_SET);
	fread(image, 1, bmpheader.image_size, file);

	for (int imageidx = 0;imageidx < bmpheader.image_size; imageidx+=3) // fixed semicolon
	{
		unsigned char temprgb = image[imageidx];
		image[imageidx] = image[imageidx + 2];
		image[imageidx + 2] = temprgb;
	}
	texture.width = bmpheader.width;
	texture.height = bmpheader.height;
	texture.image = image;

	fclose(file);
	return texture;
}