#include "pixel.h"
#include "image.h"
#include <iostream>
using namespace std;

int main()
{
	Image im(1024,768,GREEN);
	im.write("a.ppm");
}