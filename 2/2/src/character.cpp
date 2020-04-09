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

