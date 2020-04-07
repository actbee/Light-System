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
bool snack::in_body(int inx, int iny) {
	bool check = false;
	for (int i = 0; i < length; i++) {
		if (body.front().x == inx && body.front().y == iny) {
			check = true;
		}
		body.push(body.front());
		body.pop();
	}
	return check;
}

void snack::add(int inx, int iny) {
	int newx =x+inx;
	int newy=y+ iny;
	bool in=in_body(newx, newy);
	if (in == false) {
		x = newx;
		y = newy;
		body.pop();
		body.push(ofPoint(x, y));
	}
	else {
		cout << "add error." << endl;
	}
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

void snack::addlength() {
	int lastx = body.front().x;
	int lasty = body.front().y;
	int newx;
	int newy;
	if (in_body(lastx - 1, lasty) == false) {
		newx = lastx - 1;
		newy = lasty;
	}
	else if (in_body(lastx + 1, lasty) == false) {
		newx = lastx +1;
		newy = lasty;
	}
	else if (in_body(lastx , lasty-1) == false) {
		newx = lastx;
		newy = lasty-1;
	}
	else if (in_body(lastx, lasty+1) == false) {
		newx = lastx;
		newy = lasty+1;
	}
	length += 1;
	body.push(ofPoint(newx,newy));
	for (int i = 0; i < length -1; i++) {
		body.push(body.front());
		body.pop();
	}
}