#ifndef CIRCLE_H
#define CIRCLE_H

#include "../image.h"
#include "line.h"
#include <cmath>

class Circle : public Shape
{
	int cx, cy, r; //center x, center y and radius
	int initial_angle, final_angle;
	Color p; //color of the circle
public:
	Circle(int cx_, int cy_, int r_, Color p_ = BLACK, int ia = 0, int fa = 360)
	{
		cx = cx_;
		cy = cy_;
		r = r_;
		p = p_;
		initial_angle = ia;
		final_angle = fa;
	}
	void draw(Image*);
};

/**
	The circle method draws using the lines.
	Inefficient, to change.
*/
void Circle::draw(Image *im)
{
	for (float deg = 2*M_PI/360*(float)initial_angle; deg <= 2*M_PI/360*(float)final_angle; deg += M_PI/180)
	{
		float y = cy + r*sin(deg);
		float y_ = cy + r*sin(deg+M_PI/180);
		float x = cx + r*cos(deg);
		float x_ = cx + r*cos(deg+M_PI/180);
		Line *l = new Line(x,y,x_,y_,p);
		im->draw(l);
	}
}

#endif //CIRCLE_H