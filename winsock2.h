/* winsock init*/

#include<stdio.h>
#include<winsock2.h>
#include "network_struct.h"
#pragma comment(lib,"ws2_32.lib") 

int main(int argc , char *argv[])
{
	WSADATA wsa;
    SOCKET socketDescriptor;
	
	printf("\nWinsock Init...");
	if (WSAStartup(MAKEWORD(2,2),&wsa) != 0)
	{
		printf("Failed to proceed with the initialization  : %d",WSAGetLastError());
		return 1;
	}
	
	printf("Initialised.\n");

	if((socketDescriptor = socket(AF_INET , SOCK_STREAM , 0 )) == INVALID_SOCKET)
	{
		printf("Socket creation is not possible : %d" , WSAGetLastError());
	}

	printf("Socket created.\n");

	return 0;
}
