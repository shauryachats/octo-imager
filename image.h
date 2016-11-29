#ifndef IMAGE_H
#define IMAGE_H

#include "pixel.h"
#include <vector>
#include <fstream>

class Image
{
	int height, width;
	Pixel **image;

public:
	Image(int, int, Pixel);
	void write(const char *filename);
	~Image();
};

Image::Image(int height_ = 100, int width_ = 100, Pixel backColor = WHITE)
{
	height = height_, width = width_;
	
	image = new Pixel*[height];
	for (int i = 0; i < height; ++i)
	{
		image[i] = new Pixel[width];
		for (int j = 0; j < width; ++j)
			image[i][j] = backColor;	
	}	
}

void Image::write(const char *filename)
{
	std::ofstream f(filename);

	f << "P6\n";
	f << height << " " << width << '\n';
	f << "255\n";

	for (int i = 0; i < height; ++i)
		for (int j = 0; j < width; ++j)
		{
			Pixel p = image[i][j];
			f << p.getRed() << p.getGreen() << p.getBlue();
		}

	f.close();
}

Image::~Image()
{
	for (int i = 0; i < height; ++i)
		delete image[i];
	delete image;
}

#endif //IMAGE_H