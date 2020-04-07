#include"circle.h"
circle::circle() {
}
void circle::setup(float inx, float iny) {
	x = inx;
	y = iny;
	dim =30;
	color.set(0, 0, 0);
}
/*void circle::update() {
	std::cout << "every thing is fine." << endl;
}*/

void circle::draw() {
	ofSetColor(color);
	ofDrawCircle(x, y, dim);
}

float circle::getx() {
	return x;
}
float circle::gety() {
	return y;
}

int circle::getdim() {
	return dim;
}
ofColor circle::getcolor() {
	return color;
}
void circle::setcolor(ofColor incolor) {
	color=incolor;
}
