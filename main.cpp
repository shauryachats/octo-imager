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
	Image im(1366,768);
	
	// Color colors[] = {YELLOW, BROWN, VIOLET};

	for (int i = 0; i <= 1000; ++i)
	{
		Circle *c = new Circle(rand()%1366,rand()%768,rand()%100+10,MAGENTA);
		im.draw(c);
	}

	im.write("a.ppm");
}