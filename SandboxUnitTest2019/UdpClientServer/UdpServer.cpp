/*
	Simple UDP Server
*/

#include<stdio.h>
#include<winsock2.h>
#include<ws2tcpip.h>
#include <string>

#define _WINSOCK_DEPRECATED_NO_WARNINGS 1

#define BUFLEN 512	//Max length of buffer
#define IP_BUFLEN 64	//Max length of buffer

#define PORT 8888	//The port on which to listen for incoming data

int main() {
	SOCKET s;
	struct sockaddr_in server, si_other;
	int slen, recv_len;
	char buf[BUFLEN];
	WSADATA wsa;

	slen = sizeof(si_other);

	//Initialise winsock
	printf("\nInitialising Winsock...");
	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0) {
		printf("Failed.Error Code : %d" , WSAGetLastError());
		exit(EXIT_FAILURE);
	}
	printf("Initialised.\n");

	//Create a socket
	if ((s = socket(AF_INET, SOCK_DGRAM, 0)) == INVALID_SOCKET) {
		printf("Could not create socket : %d", WSAGetLastError());
	}
	printf("Socket created.\n");

	//Prepare the sockaddr_in structure
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = INADDR_ANY;
	server.sin_port = htons(PORT);

	//Bind
	if (bind(s, (struct sockaddr*) &server, sizeof(server)) == SOCKET_ERROR) {
		printf("Bind failed with error code : %d", WSAGetLastError());
		exit(EXIT_FAILURE);
	}
	puts("Bind done");

	//keep listening for data
	while (1) {
		printf("Waiting for data...");
		fflush(stdout);

		//clear the buffer by filling null, it might have previously received data
		memset(buf, '\0', BUFLEN);

		//try to receive some data, this is a blocking call
		if ((recv_len = recvfrom(s, buf, BUFLEN, 0, (struct sockaddr*) &si_other, &slen)) == SOCKET_ERROR) {
			printf("recvfrom() failed with error code : %d", WSAGetLastError());
			exit(EXIT_FAILURE);
		}

		//print details of the client/peer and the data received
//		std::wstring addrStr;
//		PWSTR pwstr;
	//	char addrStr[16];

		char ipstr[IP_BUFLEN];
		InetNtop(AF_INET, &si_other.sin_addr.s_addr, (PWSTR)ipstr, IP_BUFLEN/2);
		printf("Received packet from %s: %d\n", ipstr, ntohs(si_other.sin_port));
//		printf("Received packet from %s: %d\n" , inet_ntoa(si_other.sin_addr), ntohs(si_other.sin_port));
		printf("Data: % s\n", buf);

		//now reply the client with the same data
		if (sendto(s, buf, recv_len, 0, (struct sockaddr*) &si_other, slen) == SOCKET_ERROR) {
			printf("sendto() failed with error code : % d", WSAGetLastError());
			exit(EXIT_FAILURE);
		}
	}

	closesocket(s);
	WSACleanup();

	return 0;
}

