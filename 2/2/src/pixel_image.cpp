#include"pixel_image.h"

pixel_image::pixel_image() {
	topleft = ofPoint(0, 0);
	timeflow = 0;
	width = 0;
	height = 0;
}


pixel_image::pixel_image(int t, int h, int w) {
	topleft = ofPoint(0, 0);
	timeflow = t;
	width = w;
	height = h;
	images = new int**[timeflow];
	for (int i = 0; i < timeflow; i++) {
		images[i] = new int*[height];
	}
	for (int i = 0; i < timeflow; i++) {
		for (int j = 0; j < height; j++) {
			images[i][j] = new int[width];
		}
	}
	for (int i = 0; i < timeflow; i++) {
		for (int j = 0; j <height; j++) {
			for (int k = 0; k < width; k++) {
				images[i][j][k] = 0;
			}
		}
	}
}

pixel_image::~pixel_image() {
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			delete []images[i][j];
		}
	}
	for (int i = 0; i < timeflow; i++) {
		delete []images[i];
	}
	delete []images;
}

void pixel_image::changesize(int t, int h, int w) {
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			delete[]images[i][j];
		}
	}
	for (int i = 0; i < timeflow; i++) {
		delete[]images[i];
	}
	timeflow = t;
	height = h;
	width = w;
	images = new int**[timeflow];
	for (int i = 0; i < timeflow; i++) {
		images[i] = new int*[height];
	}
	for (int i = 0; i < timeflow; i++) {
		for (int j = 0; j < height; j++) {
			images[i][j] = new int[width];
		}
	}
	for (int i = 0; i < timeflow; i++) {
		for (int j = 0; j < height; j++) {
			for (int k = 0; k < width; k++) {
				images[i][j][k] = 0;
			}
		}
	}
}

void pixel_image::setpixels(int t, int x,int y, int num) {
	if (t >= timeflow || x >= height || y >= width) {
		cout << "invalid operation!" << endl;
		return;
	}
	images[t][x][y] = num;

}


int pixel_image::getpixels(int t, int i, int j) {
	if (t >= timeflow || i >= height || j >= width) {
		cout << "invalid operation!" << endl;
		return -1;
	}
	return images[t][i][j];
}

void pixel_image::settopleft(int x,int y) {
	topleft = ofPoint(x, y);
}
