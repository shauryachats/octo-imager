#ifndef RECT_H_
#define RECT_H_

#include "../shape.h"
#include "line.h"

class Rect : public Shape
{
	int lcx, lcy, rcx, rcy;
	Color c;
public:
	Rect() {}
	Rect(int lcx_, int lcy_, int rcx_, int rcy_, Color c_ = BLACK)
	{
		lcx = lcx_;
		lcy = lcy_;
		rcx = rcx_;
		rcy = rcy_;
		c = c_;
	}
	void draw(Image *image);
};

void Rect::draw(Image *image)
{
	Line *l = new Line(lcx, lcy, rcx, lcy, c);
	image->draw(l);
	l = new Line(lcx, lcy, lcx, rcy, c);
	image->draw(l);
	l = new Line(rcx, rcy, lcx, rcy, c);
	image->draw(l);
	l = new Line(rcx, rcy, rcx, lcy, c);
	image->draw(l);
}

#endif //RECT_H_