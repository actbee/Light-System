#include"sender.h"
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
	recvaddr.sin_addr.s_addr = inet_addr("192.168.1.110");
}

void sender::senddate(string output) {
	char* words;
	strcpy(words, output.c_str());
	sendto(sendsocket, words, buflen, 0, (sockaddr*)&recvaddr, sizeof(recvaddr));
}

void sender::close() {
	closesocket(sendsocket);
	WSACleanup();
}