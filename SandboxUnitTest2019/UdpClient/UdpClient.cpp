// UdpClient.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

/*
	Simple udp client
*/
#include <stdio.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <string>

#pragma comment(lib,"ws2_32.lib") //Winsock Library

#define SERVER "127.0.0.1"	//ip address of udp server
#define BUFLEN 512	//Max length of buffer
#define PORT 8888	//The port on which to listen for incoming data

int main(void)
{
	struct sockaddr_in si_other;
	int s, slen = sizeof(si_other);
	char buf[BUFLEN];
	char message[BUFLEN];
	WSADATA wsa;

	//Initialise winsock
	printf("\nInitialising Winsock... ");
	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
	{
		printf("Failed.Error Code : % d " , WSAGetLastError());
		exit(EXIT_FAILURE);
	}
	printf("Initialised.\n ");

	//create socket
	if ((s = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) == SOCKET_ERROR)
	{
		printf("socket() failed with error code : % d ", WSAGetLastError());
		exit(EXIT_FAILURE);
	}

	//setup address structure
	memset((char*)&si_other, 0, sizeof(si_other));
	si_other.sin_family = AF_INET;
	si_other.sin_port = htons(PORT);

//	si_other.sin_addr.S_un.S_addr = inet_addr(SERVER);

	char addrStr[INET6_ADDRSTRLEN] = {};
	char addrStr2[INET6_ADDRSTRLEN] = {};

	strcpy_s(addrStr, SERVER);
//	strcpy_s(addrStr, "192.168.1.71");

	printf("server: %s, addrStr: %s\n", SERVER, addrStr);

	inet_pton(AF_INET, (PCSTR)addrStr, &(si_other.sin_addr));
//	printf("server: %s, addrStr: %s\n", si_other.sin_addr, addrStr);

	// verify that we stored it correctly
	inet_ntop(AF_INET, &(si_other.sin_addr), addrStr2, INET_ADDRSTRLEN);
	printf("address after conversion back from sin_addr = %s\n", addrStr2);

	//char ipstr[IP_BUFLEN];
	//InetNtop(AF_INET, &si_other.sin_addr.s_addr, (PWSTR)ipstr, IP_BUFLEN / 2);
	//printf("Received packet from %s: %d\n", ipstr, ntohs(si_other.sin_port));


	//start communication
	while (1)
	{
		printf("Enter message : ");
		fgets(message, BUFLEN, stdin);

		//send the message
		if (sendto(s, message, strlen(message), 0, (struct sockaddr*) &si_other, slen) == SOCKET_ERROR)
		{
			printf("sendto() failed with error code : % d ", WSAGetLastError());
			exit(EXIT_FAILURE);
		}

		//receive a reply and print it
		//clear the buffer by filling null, it might have previously received data
		memset(buf, '\0', BUFLEN);
		//try to receive some data, this is a blocking call
		if (recvfrom(s, buf, BUFLEN, 0, (struct sockaddr*) &si_other, &slen) == SOCKET_ERROR)
		{
			printf("recvfrom() failed with error code : % d ", WSAGetLastError());
			exit(EXIT_FAILURE);
		}

		fputs(buf, stdout);
	}

	closesocket(s);
	WSACleanup();

	return 0;
}
