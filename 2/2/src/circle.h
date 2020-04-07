#ifndef _circle
#define _circle
#include "ofMain.h"
class circle {
public:

	void setup(float inx, float iny);
//	void update();
	void draw();
	float getx();
	float gety();
	int getdim();
	ofColor getcolor();
	void setcolor(ofColor incolor);
	circle();

private:

	float x;
	float y;
	int dim;
	ofColor color;
};
#endif