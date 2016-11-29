/**
	octo-imager, a NetPBM imager library.
*/

#include "point.h"
#include <stdlib.h>

int main()
{
	srand(time(NULL));
	//create an image file of 100x100, background in green color.
	Image im(200,200,BLUE);
	//create a new point at 50x50 which is black in color.
	for (int i = 0; i < 100; ++i)
	{
		Point *p = new Point(rand()%200,rand()%200, Pixel("#00F000"));
		im.addtoqueue(p);
	}
	//write image to file.
	im.write("a.ppm");
}