#ifndef PIXEL_H
#define PIXEL_H

#include <string>
#include <stdlib.h>

struct Pixel
{
	//for more memory saving, use unsigned char (0 - 255)
	unsigned char r, g, b;

	//ctors.
	Pixel() { r = g = b = 0; }
	Pixel(int r_, int g_, int b_) : r(r_), g(g_), b(b_) {};
	Pixel(const char *s);

	//getters
	unsigned char getRed() { return r; }
	unsigned char getGreen() { return g; }
	unsigned char getBlue() { return b; }

	//setters
	void setRed(unsigned char r_) { r = r_; }
	void setGreen(unsigned char g_) { g = g_; }
	void setBlue(unsigned char b_) { b = b_; }
	void setRGB(unsigned char r_, unsigned char g_, unsigned char b_) { r = r_, g = g_, b = b_; }
	void setRGB(const char *s);

	//== overrating
	bool operator==(const Pixel &p) {
		return (r == p.r && g == p.g && b == p.b);
	}
};

/**
	Defining pixel colors with hexcode.
*/
void Pixel::setRGB(const char *hexcode)
{
	std::string str(hexcode);
	char *p;

	r = strtol(str.substr(1,2).c_str(), &p, 16);
	g = strtol(str.substr(3,2).c_str(), &p, 16);
	b = strtol(str.substr(5,2).c_str(), &p, 16);

}

/**
	Ctor with hexcode.
*/
Pixel::Pixel(const char *hexcode)
{
	std::string str(hexcode);
	char *p;

	r = strtol(str.substr(1,2).c_str(), &p, 16);
	g = strtol(str.substr(3,2).c_str(), &p, 16);
	b = strtol(str.substr(5,2).c_str(), &p, 16);	
}

/**
	Alpha(Pixel topcolor, Pixel bottomcolor, float alpha) 
*/
Pixel Alpha(Pixel topcolor, Pixel bottomcolor, float alpha)
{
	if (alpha < 0) alpha = 0;
	if (alpha > 1) alpha = 0;
	int r = topcolor.getRed() * alpha + bottomcolor.getRed() * (1 - alpha);
	int g = topcolor.getGreen() * alpha + bottomcolor.getGreen() * (1 - alpha);
	int b = topcolor.getBlue() * alpha + bottomcolor.getBlue() * (1 - alpha);
	return Pixel(r,g,b);
}

//Predefined colours.
const Pixel BLACK(0,0,0);
const Pixel WHITE(255,255,255);
const Pixel RED(255,0,0);
const Pixel GREEN(0,255,0);
const Pixel BLUE(0,0,255);

#endif //PIXEL_H