#include"snack.h"


ofPoint snack::get_before() {
	return before_head;
}

bool  snack::dead() {
	return is_dead;
}

void snack::setup(int inx, int iny, int inlength,ofColor incolor) {
	head.x = inx;
	head.y = iny;
	color = incolor;
	length = inlength;
	while(!body.empty()) {
		body.pop();
	}
	for (int i = length - 1;  i >= 0; i--) {
		int xx = head.x - i;
		body.push(ofPoint(xx, head.y));
	}
	/*for (int i = 0; i < body.size(); i++) {
		cout << body.front().x << "," << body.front().y << endl;
		body.push(body.front());
		body.pop();
	}*/
	is_dead = false;
	before_head.x = head.x - 1;
	before_head.y = head.y;
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
	int newx =head.x+inx;
	int newy=head.y+ iny;
	bool in=in_body(newx, newy);
	if (in == false) {
		before_head = head;
		head.x = newx;
		head.y = newy;
		body.pop();
		body.push(ofPoint(head.x, head.y));
	}
	else {
		if (newx == before_head.x&&newy==before_head.y) {
			cout << "add error." << endl;
		}
		else {
			before_head = head;
			head.x = newx;
			head.y = newy;
			body.pop();
			body.push(ofPoint(head.x, head.y));
			is_dead = true;
		}
	}
}

ofPoint snack::get_head() {
	return head;
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
void snack::sublength() {
	if (length == 0) {
		cout << "error" << endl;
		return;
	}
	length -= 1;
	body.pop();
}