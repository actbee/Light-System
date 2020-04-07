#include"target.h"

void target::setup(int inx, int iny, ofColor incolor) {
	pos.x = inx;
	pos.y = iny;
	color = incolor;
}

int target::get_x() {
	return pos.x;
}

int target::get_y() {
	return pos.y;
}

ofColor target::get_color() {
	return color;
}