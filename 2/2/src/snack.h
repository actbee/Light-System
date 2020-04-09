#ifndef _sncak
#define _snack
#include "ofMain.h"
#include<queue>
#include<stdlib.h>
class snack {
public:
	void setup(int inx, int iny, int length, ofColor incolor);
	void add(int inx,int iny);
	ofPoint get_head();
	ofPoint get_before();
	ofColor getcolor();
	int getlength();
	queue<ofPoint> body;
	bool in_body(int inx,int iny);
	void addlength();
	bool dead();
private:
	ofPoint head;    //the head position
	ofPoint before_head;
	int length;
	ofColor color;
	bool is_dead;
};

#endif