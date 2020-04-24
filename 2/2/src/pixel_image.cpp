#include"pixel_image.h"

pixel_image::pixel_image() {
	topleft = ofPoint(0, 0);
	timeflow = 0;
	width = 0;
	height = 0;
	v = ofPoint(0, 0);
	toup = 0;
	toleft = 0;
	toright = 0;
	todown = 0;
}


pixel_image::pixel_image(int t, int h, int w) {
	topleft = ofPoint(0, 0);
	v = ofPoint(0, 0);
	timeflow = t;
	width = w;
	height = h;
	toup = 0;
	toleft = 0;
	toright = 0;
	todown = 0;
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
	for (int i = 0; i <height; i++) {
		delete []images[i];
	}
	delete []images;
}

void pixel_image::changesize(int t, int h, int w) {
	/*for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			delete[]images[i][j];
		}
	}
	cout << "delete1 success" << endl;
	for (int i = 0; i < height; i++) {
		delete[]images[i];
	}
	cout << "delete2 success" << endl;
	delete[]images;
	cout << "delete3 success" << endl;
	*/
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

int pixel_image::getposition(int t, int i, int j) {
	int xx= i - topleft.x;
	int yy = j - topleft.y;
	if (0 <= xx && xx < width && 0 <= yy && yy < height&&t<timeflow&&t>=0) {
		return images[t][yy][xx];
	}
	return 0;
}

ofPoint pixel_image::gettopleft() {
	return topleft;
}

void pixel_image::settopleft(int x,int y) {
	topleft = ofPoint(x, y);
}

void pixel_image::move_down() {
	topleft.y += 1;
}
void pixel_image::move_up() {
	topleft.y -= 1;
}
void pixel_image::move_left() {
	topleft.x -= 1;
}
void pixel_image::move_right() {
	topleft.x += 1;
}

void pixel_image::change_v(int x, int y) {
	if (v.x >= 0) {
		v.x = x;
	}
	else {
		v.x = -x;
	}
	if (v.y >= 0) {
		v.y = y;
	}
	else {
		v.y = -y;
	}
}

void pixel_image::setboard(int x1, int x2, int y1, int y2) {
	toright = x1;
	toleft = x2;
	toup = y1;
	todown = y2;
}

void pixel_image::update() {
	
	if ((v.x > 0 && topleft.x > 14-toright)||(v.x < 0 && topleft.x + width-1 < 0+toleft)){
		v.x = -v.x;
	}
	if ((v.y > 0 && topleft.y>9-todown)||(v.y<0&&topleft.y+height-1<0+toup)) {
		v.y=-v.y;
	}
    topleft.x += v.x;
	topleft.y += v.y;
}

int pixel_image::gettimeflow() {
	return timeflow;
}




