#ifndef _target
#define _target
#include"ofMain.h"

class target {
public:
	void setup(int x,int y,ofColor incolor);
	int get_x();
	int get_y();
	ofColor get_color();
private:
	ofPoint pos;
	ofColor color;
};

#endif
