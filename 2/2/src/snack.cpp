#include"snack.h"

void snack::setup(int inx, int iny, int inlength,ofColor incolor) {
	x = inx;
	y = iny;
	color = incolor;
	length = inlength;
	for (int i = length - 1;  i >= 0; i--) {
		int xx = x - i;
		body.push(ofPoint(xx, y));
	}
}
void snack::add(int inx, int iny) {
	    x += inx;
		y += iny;
		body.pop();
		body.push(ofPoint(x, y));
}
int snack::getx() {
	return x;
}
int snack::gety() {
	return y;
}
ofColor snack::getcolor() {
	return color;
}
int snack::getlength() {
	return length;
}