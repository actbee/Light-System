#ifndef _pixel_image
#define _pixel_image
#include"ofMain.h"

class pixel_image {
public:
	pixel_image(int t, int h, int w );
	pixel_image();
	~pixel_image();
	void setpixels(int t, int x,int y, int num);
	void changesize(int t, int h, int w);
	int getpixels(int t, int i, int j);
	int getposition(int t, int i, int j);
	ofPoint gettopleft();
	void settopleft(int x,int y);
	void move_left();
	void move_right();
	void move_up();
	void move_down();
	void update();
	void change_v(int x, int y);
	void setboard(int x1, int x2, int y1, int y2);

private:
	int*** images;
	int timeflow;
	int width;
	int height;
	ofPoint topleft;
	ofPoint v;
	int toup;
	int todown;
	int toleft;
	int toright;
};

#endif
