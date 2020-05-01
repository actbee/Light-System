#ifndef _sender
#define _sender
#include<WINSOCK2.H>
#include<string>
using std::string;

class sender {
public:
	sender();
	~sender();
	void senddate(string output);
	void close();
};

#endif