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
	void settopleft(int x,int y);
private:
	int*** images;
	int timeflow;
	int width;
	int height;
	ofPoint topleft;
};

#endif
