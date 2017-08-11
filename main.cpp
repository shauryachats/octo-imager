/**
	octo-imager, a NetPBM imager library.
*/

#include "shapes/point.h"
#include "shapes/line.h"
#include "shapes/circle.h"
#include "shapes/rect.h"
#include <stdlib.h>

int main()
{
	srand(time(NULL));
	//create an image file of 100x100, background in green color.
	int w = 1366, h = 768;
	Image im(1366,768);
	
	// Color colors[] = {YELLOW, BROWN, VIOLET};

	for (int i = 0; i <= 200; ++i)
	{
		Rect *s = new Rect(rand()%w,rand()%h,rand()%w,rand()%h,getRandomColor());
		im.draw(s);
	}

	im.write("a.ppm");
}