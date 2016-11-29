#ifndef SHAPE_H
#define SHAPE_H

/*
	Shape is a purely abstract class, which can just be inherited
	to define our own shape.
*/

//forward declaration.
class Image; 

class Shape
{
public:
	virtual void draw(Image *image) {};
};

#endif //SHAPE_H