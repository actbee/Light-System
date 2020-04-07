#ifndef _sncak
#define _snack
#include "ofMain.h"
#include<queue>
#include<stdlib.h>
class snack {
public:
	void setup(int inx, int iny, int length, ofColor incolor);
	void add(int inx,int iny);
	int getx();
	int gety();
	ofColor getcolor();
	int getlength();
	queue<ofPoint> body;
	bool in_body(int inx,int iny);
	void addlength();
private:
	int x;    //the head position
	int y;
	int length;
	ofColor color;
};

#endif