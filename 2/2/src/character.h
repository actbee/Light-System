#ifndef _character
#define _character
#include"ofMain.h"

class character {
public:
	void move(ofPoint newtopleft);
	character(int in[][4], int n);
	character();
	void change(int in[][4], int n);
	int words[7][4];
	ofPoint get_topleft();
	ofPoint get_topright();
	void reset();
private:
	ofPoint topleft;
};

#endif