#include"sender.h"
#include"iostream"
#pragma comment(lib,"ws2_32.lib")
WSADATA wsadata;
SOCKET sendsocket;
sockaddr_in recvaddr;
int PORT = 5525;
char sendbuf[1024];
int buflen = 1024;

sender::sender() {
	WSAStartup(MAKEWORD(2, 2), &wsadata);
	sendsocket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
	recvaddr.sin_family = AF_INET;
	recvaddr.sin_port = htons(PORT);
	recvaddr.sin_addr.s_addr = inet_addr("60.255.136.62");
}

sender::~sender() {
	close();
}

void sender::senddata(std::string output) {
	char words[301];    //there must be a better way to translate the string to char array, need to improve here
	strcpy(words, output.c_str());
	std::cout <<"send it:"<< words <<std::endl;
	sendto(sendsocket, words, sizeof(words), 0, (sockaddr*)&recvaddr, sizeof(recvaddr));
}

void sender::close() {
	closesocket(sendsocket);
	WSACleanup();
}