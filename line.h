#ifndef LINE_H
#define LINE_H

#include "image.h"
#include <cmath>
#include <algorithm>

class Line : public Shape
{
	//line from (x1,y1) to (x2,y2)
	int x1, y1, x2, y2;
	bool antialias;
	Color p; //color of the line
public:
	Line(int x1_, int y1_, int x2_, int y2_, Color p_ = BLACK, bool antialias_ = true)
	{
		x1 = x1_;
		y1 = y1_;
		x2 = x2_;
		y2 = y2_;
		p = p_;
		antialias = antialias_;
	}
	void draw(Image*);
};

//TODO : Add antialiasing
void Line::draw(Image *image)
{
	int ydiff = y2 - y1;
	int xdiff = x2 - x1;

	double slope = ydiff;
	slope /= xdiff;

	double x, y;

	//drawing with major movement in y.
	if (abs(ydiff) >= abs(xdiff))
	{
		slope = 1/slope;

		if (y1 > y2) 
		{
			std::swap(y1, y2);
			std::swap(x1, x2);
		}

		x = x1, y = y1;

		while (y <= y2)
		{
			image->draw(round(x),y,p,1.0);
			y++;
			x += slope;
		}
	}
	else //drawing with major movement in x.
 	{
 		if (x1 > x2) 
 		{
 			std::swap(x1, x2);
 			std::swap(y1, y2);
 		}

 		x = x1, y = y1;

 		while (x <= x2)
 		{
 			image->draw(x, round(y), p, 1.0);
 			x++;
 			y += slope;
 		}
	}
}

#endif //LINE_H