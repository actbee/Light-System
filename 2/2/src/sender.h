#ifndef _sender
#define _sender
#include<WINSOCK2.H>
#include<string>
//using namespace std;

class sender {
public:
	sender();
	~sender();
	void senddata(std::string output);
	void close();
};

#endif