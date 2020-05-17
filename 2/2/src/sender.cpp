#include"sender.h"
#include"iostream"
#pragma comment(lib,"ws2_32.lib")
WSADATA wsadata;
SOCKET sendsocket;
sockaddr_in recvaddr;
int PORT = 8000;
char sendbuf[1024];
int buflen = 1024;

sender::sender() {
	WSAStartup(MAKEWORD(2, 2), &wsadata);
	sendsocket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
	recvaddr.sin_family = AF_INET;
	recvaddr.sin_port = htons(PORT);
	recvaddr.sin_addr.s_addr = inet_addr("192.168.23.222");
}

sender::~sender() {
	close();
}

void sender::senddata(std::string output) {
	char words[151];    //there must be a better way to translate the string to char array, need to improve here
	char words2[151];
	strcpy(words2, output.c_str());
	words[0]=0XBB;
	for (int i = 1; i < 151; i++) {
		if(words2[i-1]=='1')
		words[i] =0x01;
		else if (words2[i - 1] == '2')
			words[i] = 0x02;
		else if (words2[i - 1] == '3')
			words[i] = 0x03;
		else if (words2[i - 1] == '0')
			words[i] = 0x00;
	}
	//char words[2] = "0";
	sendto(sendsocket, words, sizeof(words), 0, (sockaddr*)&recvaddr, sizeof(recvaddr));
//	recvmain();    //test if the send success
}

void sender::recvmain() {
		char s[2048];
		sockaddr_in sfrom = { 0 };
		int slen = sizeof(sfrom);//in out
		SOCKET sock = (SOCKET)sendsocket;
		int n = 0;
		if((n = recvfrom(sock, s, sizeof(s), 0, (sockaddr*)&sfrom, &slen)) > 0)
		{
			s[n] = '\0';
		//	cout << WSAGetLastError() << endl;
			std::cout << std::endl << "receive messeage" << inet_ntoa(sfrom.sin_addr) << "-" << htons(sfrom.sin_port) << ": " << s << std::endl;
		}
}

void sender::close() {
	closesocket(sendsocket);
	WSACleanup();
}