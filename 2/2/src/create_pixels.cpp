#include"ofApp.h"
#include"make_dll.h"
void create_pixel_alien(pixel_image& mypixels) {
	mypixels.changesize(3, 11, 16);
	for (int i = 0; i < 11; i++) {
		for (int j = 0; j < 16; j++) {
			mypixels.setpixels(0, i, j, pixel_alien_l[i][j]);
		}
	}
	for (int i = 0; i < 11; i++) {
		for (int j = 0; j < 16; j++) {
			mypixels.setpixels(1, i, j, pixel_alien[i][j]);
		}
	}
	for (int i = 0; i < 11; i++) {
		for (int j = 0; j < 16; j++) {
			mypixels.setpixels(2, i, j, pixel_alien_r[i][j]);
		}
	}
}


//--------------------------------------------------------------
void create_pixel_fly(pixel_image& mypixels) {
	mypixels.changesize(6, 8, 11);
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 11; j++) {
			mypixels.setpixels(0, i, j, pixel_fly_one[i][j]);
		}
	}
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 11; j++) {
			mypixels.setpixels(1, i, j, pixel_fly_two[i][j]);
		}
	}
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 11; j++) {
			mypixels.setpixels(2, i, j, pixel_fly_three[i][j]);
		}
	}
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 11; j++) {
			mypixels.setpixels(3, i, j, pixel_fly_four[i][j]);
		}
	}
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 11; j++) {
			mypixels.setpixels(4, i, j, pixel_fly_five[i][j]);
		}
	}
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 11; j++) {
			mypixels.setpixels(5, i, j, pixel_fly_six[i][j]);
		}
	}
}

//--------------------------------------------------------------

void create_pixel_acaleph(pixel_image& mypixels) {
	mypixels.changesize(3, 8, 8);
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			mypixels.setpixels(0, i, j, pixel_acaleph_1[i][j]);
		}
	}
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			mypixels.setpixels(1, i, j, pixel_acaleph_2[i][j]);
		}
	}
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			mypixels.setpixels(2, i, j, pixel_acaleph_3[i][j]);
		}
	}
}

//--------------------------------------------------------------

void create_pixel_bubble(pixel_image& mypixels) {
	mypixels.changesize(4, 9, 9);
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			mypixels.setpixels(0, i, j, pixel_bubble_1[i][j]);
		}
	}
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			mypixels.setpixels(1, i, j, pixel_bubble_2[i][j]);
		}
	}
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			mypixels.setpixels(2, i, j, pixel_bubble_3[i][j]);
		}
	}
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			mypixels.setpixels(3, i, j, pixel_bubble_4[i][j]);
		}
	}
}

//--------------------------------------------------------------

void create_pixel_evil(pixel_image& mypixels) {
	mypixels.changesize(5, 8, 12);
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 12; j++) {
			mypixels.setpixels(0, i, j, pixel_evil_1[i][j]);
		}
	}
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 12; j++) {
			mypixels.setpixels(1, i, j, pixel_evil_2[i][j]);
		}
	}
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 12; j++) {
			mypixels.setpixels(2, i, j, pixel_evil_3[i][j]);
		}
	}
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 12; j++) {
			mypixels.setpixels(3, i, j, pixel_evil_4[i][j]);
		}
	}
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 12; j++) {
			mypixels.setpixels(4, i, j, pixel_evil_5[i][j]);
		}
	}
}