#ifndef SHAPE_H
#define SHAPE_H

/*
	Shape is a purely abstract class, which can just be inherited
	to define our own shape.

	Every geometric shape should derive public from Shape, to let
	Image access the draw().
*/

//forward declaration.
class Image; 

class Shape
{
public:
	virtual void draw(Image*);
};

void Shape::draw(Image *image)
{

}

#endif //SHAPE_H