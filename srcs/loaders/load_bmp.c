#include "bmpheader.h"
#include "opengl_simple_render.h"

t_bmpheader	read_and_check_bmpheader(FILE *file)
{
	t_bmpheader	bmpheader;

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
	fread(&bmpheader.color_important, 4, 1, file);
	bmpheader.width = bmpheader.width < 0 ? -bmpheader.width : bmpheader.width;
	bmpheader.height = bmpheader.height < 0 ? -bmpheader.height : bmpheader.height;
	return bmpheader;
}

t_texture load_bmp(const char *filename)
{
	t_texture texture;
	FILE *file;
	t_bmpheader bmpheader;

	file = fopen(filename, "rb");
	if (!file)
		ft_exit_with_error((const char *[])
		{"FILE PATH: ", filename, " DOESN'T CORRECT", NULL}, -1);
	bmpheader = read_and_check_bmpheader(file);
	bmpheader.image_size = bmpheader.width * bmpheader.height * (bmpheader.bit_per_pixel / 8);
	unsigned char *image = (unsigned char *) malloc(bmpheader.image_size + 1);
	fseek(file, bmpheader.offset_bits, SEEK_SET);
	fread(image, 1, bmpheader.image_size, file);
	for (unsigned imageidx = 0; imageidx < bmpheader.image_size; imageidx += 3) // fixed semicolon
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