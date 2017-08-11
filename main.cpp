/**
	octo-imager, a NetPBM imager library.
*/

#include "shapes/point.h"
#include "shapes/line.h"
#include "shapes/circle.h"
#include <stdlib.h>

int main()
{
	srand(time(NULL));
	//create an image file of 100x100, background in green color.
	Image im(200,200);
	
	Line *l = new Line(100, 120, 20, 120);
	Line *l2 = new Line(100, 120, 100, 20, RED);
	Line *l3 = new Line(20, 50, 100, 120, BLUE);

	im.draw(l);
	im.draw(l2);
	im.draw(l3);

	im.write("a.ppm");
}