#ifndef LINE_H
#define LINE_H

#include "image.h"
#include <cmath>

class Line : public Shape
{
	//line from (x1,y1) to (x2,y2)
	int x1, y1, x2, y2;
	Pixel p;
public:
	Line(int x1_, int y1_, int x2_, int y2_, Pixel p_) : 
		x1(x1_), y1(y1_), x2(x2_), y2(y2_), p(p_) {}
	void draw(Image*);
};

void Line::draw(Image *im)
{
	float yslope = (float)(y2 - y1)/(x2 - x1);
	float xslope = (float)(x2 - x1)/(y2 - y1);

	//if slope is not infinity, draw.
	if (!std::isinf(fabs(yslope)))
	for (int x = std::min(x1,x2); x <= std::max(x1,x2); ++x)
	{
		int y = y1 + yslope * (x - x1);
 		im->add(y,x,p,1);
 	}

 	if (!std::isinf(fabs(xslope)))
 	for (int y = std::min(y1,y2); y <= std::max(y1,y2); ++y)
 	{
 		int x = x1 + (y - y1) * xslope;
 		im->add(y,x,p,1);
 	}
}

#endif //LINE_H