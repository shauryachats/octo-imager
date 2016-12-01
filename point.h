#ifndef POINT_H
#define POINT_H

#include "shape.h"
#include "image.h"
#include <iostream>

class Point : public Shape
{
	int x, y;
	float alpha;
	Pixel p;
public:
	Point(int, int, Pixel, float);
	void draw(Image*);
};

Point::Point(int x_ = 0, int y_ = 0, Pixel p_ = BLACK, float alpha_ = 1.0) : 
	x(x_), y(y_), p(p_), alpha(alpha_) {};

/*
	The draw() for Point which will be called.
*/
void Point::draw(Image *im)
{
	im->add(y,x,p,alpha);
}

#endif //POINT_H