#ifndef PIXEL_H
#define PIXEL_H

struct Pixel
{
	//for more memory saving, use unsigned char (0 - 255)
	unsigned char r, g, b;
	
	//ctors.
	Pixel() { r = g = b = 0; }
	Pixel(int r_, int g_, int b_) : r(r_), g(g_), b(b_) {};

	//getters
	unsigned char getRed() { return r; }
	unsigned char getGreen() { return g; }
	unsigned char getBlue() { return b; }

	//setters
	void setR(unsigned char r_) { r = r_; }
	void setG(unsigned char g_) { g = g_; }
	void setB(unsigned char b_) { b = b_; }
	void setRGB(unsigned char r_, unsigned char g_, unsigned char b_) { r = r_, g = g_, b = b_; }

	//== overrating
	bool operator==(const Pixel &p) {
		return (r == p.r && g == p.g && b == p.b);
	}
};

//Predefined colours.
const Pixel BLACK(0,0,0);
const Pixel WHITE(255,255,255);
const Pixel RED(255,0,0);
const Pixel GREEN(0,255,0);
const Pixel BLUE(0,0,255);

#endif //PIXEL_H