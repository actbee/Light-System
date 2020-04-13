#include"character.h"

character::character(int input[][4], int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 4; j++) {
			words[i][j] = input[i][j];
		}
	}
	topleft = ofPoint(1, 1);
}

void character::change(int input[][4], int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 4; j++) {
			words[i][j] = input[i][j];
		}
	}
}

character::character() {
	topleft = ofPoint(1, 1);
}


void character::move(ofPoint newtopleft) {
	topleft = newtopleft;
}

ofPoint character::get_topleft() {
	return topleft;
}

ofPoint character::get_topright() {
	int xx = topleft.x + 4;
	int yy = topleft.y;
	return ofPoint(xx, yy);
}

void character::reset() {
	topleft.x = 1;
	topleft.y = 1;
    int transfer[7][4] = {
	{1,1,1,1},
	{1,0,0,1},
	{1,0,0,1},
	{1,0,0,1},
	{1,0,0,1},
	{1,0,0,1},
	{1,1,1,1}
	};
	for (int i = 0; i <7; i++) {
		for (int j = 0; j < 4; j++) {
			words[i][j] = transfer[i][j];
		}
	}
}