#ifndef POINT_H
#define POINT_H

#include "../image.h"

class Point : public Shape
{
	int x, y;
	float alpha;
	Color p;
public:
	Point(int, int, Color, float);
	void draw(Image*);
};

Point::Point(int x_ = 0, int y_ = 0, Color p_ = BLACK, float alpha_ = 1.0) 
{
	x = x_;
	y = y_;
	p = p_;
	alpha = alpha_;
};

/*
	The draw() for Point which will be called.
*/
void Point::draw(Image *im)
{
	im->draw(x,y,p,alpha);
}

#endif //POINT_H