/**
	octo-imager, a NetPBM imager library.
*/

#include "point.h"
#include "line.h"
#include <stdlib.h>

int main()
{
	srand(time(NULL));
	//create an image file of 100x100, background in green color.
	Image im(500,500,WHITE);
	
	Line *l = new Line(20,50,120,120,BLACK,false);
	//Line *q = new Line(70,70,100,70,RED);
	im.addtoqueue(l);
	//im.addtoqueue(q);

	//create a new point at 50x50 which is black in color.
	/*for (int i = 0; i < 100; ++i)
	{
		Point *p = new Point(rand()%200,rand()%200, Pixel("#00F000"));
		im.addtoqueue(p);
	}*/
	//write image to file.
	im.write("a.ppm");
}