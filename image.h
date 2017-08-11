#ifndef IMAGE_H
#define IMAGE_H

#include "color.h"
#include "shape.h"

#include <vector>
#include <fstream>
#include <iostream>

class Image
{

	int height, width;
	Color **image;
	std::vector<Shape*> drawingqueue;	
	void drawqueue();	

public:
	Image(int, int, Color);
	void write(const char *filename);
	void putPixel(int, int, Color, float);
	void draw(Shape*);
	~Image();
};

/*
	Parameterized ctor for background initialization.
*/
Image::Image(int height_ = 100, int width_ = 100, Color backColor = WHITE)
{
	height = height_, width = width_;
	
	image = new Color*[height];
	for (int i = 0; i < height; ++i)
	{
		image[i] = new Color[width];
		for (int j = 0; j < width; ++j)
			image[i][j] = backColor;	
	}	
}

/*
	Writes the image to the file.
*/
void Image::write(const char *filename)
{
	//Draw the geometry queue before writing to file.
	drawqueue();

	std::ofstream f(filename);

	f << "P6\n";
	f << width << " " << height << '\n';
	f << "255\n";

	for (int i = 0; i < height; ++i)
		for (int j = 0; j < width; ++j)
		{
			Color p = image[i][j];
			f << p.getRed() << p.getGreen() << p.getBlue();
		}

	f.close();
}

/*
	Modifying a pixel in the image buffer.
*/
void Image::putPixel(int x, int y, Color p, float alpha = 1.0)
{	
	#ifdef DEBUG
	std::cerr<<"Drawing point "<<y<<','<<x<<' ';
	std::cerr<<"Color:("<<(int)p.getRed()<<','<<(int)p.getGreen()<<','<<(int)p.getBlue()<<") ";
	std::cerr<<"Alpha: "<<alpha<<'\n';
	#endif

	if (y >= 0 && y < height && x >= 0 && x < width)
	{
		image[y][x] = Alpha(p, image[y][x], alpha);
	}
}


/*
	Cleaning off stuff.
*/
Image::~Image()
{
	for (int i = 0; i < height; ++i)
		delete image[i];
	delete image;
}

/*
	Adds the given shape to the queue of drawingqueue.
*/
void Image::draw(Shape *shape)
{
	drawingqueue.push_back(shape);
}

/*
	Draw all the shapes present in the queue.
*/
void Image::drawqueue()
{
	for (int i = 0; i < drawingqueue.size(); ++i)
		drawingqueue[i]->draw(this);
}


#endif //IMAGE_H