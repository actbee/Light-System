#ifndef _sender
#define _sender
#include"ofMain.h"
#include<WINSOCK2.H>

class sender {
public:
	sender();
	~sender();
	void senddata(string output);
	void close();
};

#endif