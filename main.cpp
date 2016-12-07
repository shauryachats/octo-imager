/**
	octo-imager, a NetPBM imager library.
*/

#include "point.h"
#include "line.h"
#include "circle.h"
#include <stdlib.h>

int main()
{
	srand(time(NULL));
	//create an image file of 100x100, background in green color.
	Image im(500,500,"#222222");
	
	Circle *c = new Circle(100,100,100,Pixel("#C0FFEE"),180,270);
	im.addtoqueue(c);
	Line *l = new Line(20,50,120,120,BLACK,false);
	im.addtoqueue(l);

	im.write("a.ppm");
}