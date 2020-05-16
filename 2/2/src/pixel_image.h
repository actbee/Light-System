#ifndef _pixel_image
#define _pixel_image
#include"ofMain.h"

class pixel_image {
public:
	pixel_image(int t, int h, int w );
	pixel_image();
	~pixel_image();
	void changesize(int t, int h, int w);  //to redefine the size of the 3-array
	void setpixels(int t, int x,int y, int num);
	int getpixels(int t, int i, int j);
	int getposition(int t, int i, int j);
	ofPoint gettopleft();
	void settopleft(int x,int y);
	void move_left();
	void move_right();
	void move_up();
	void move_down();
	void update();
	void change_v(int x,int y,int mid);
	void setboard(int x1, int x2, int y1, int y2); //set the distance of the pixel to each boardline.
	int gettimeflow();

private:
	int*** images;
	int timeflow;  //the time status right now
	int width;
	int height;
	ofPoint topleft;
	ofPoint v;

	int toup;
	int todown;
	int toleft;
	int toright;

	int counter;
	int gap;

};

#endif
