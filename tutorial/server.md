# Code Breakdown

## Include Libraries:
- `#include <stdio.h>`: Includes the standard I/O library for functions like `printf`.
- `#include <winsock2.h>`: Includes the Winsock library for network programming.
- `#include "network_struct.h"`: Includes custom header for network structures.

## Link Winsock Library:
- `#pragma comment(lib, "ws2_32.lib")`: Ensures the Winsock library is linked during the build process. 🔗

###  Declare Variables:
- `WSADATA wsa;`: Structure to store details about the Windows Sockets implementation. 🔗
- `SOCKET socketDescriptor;`: Variable to store the socket descriptor. 📝

###  Print Initialization Message:
- `printf("\nWinsock Init...");`: Prints a message indicating the start of Winsock initialization.

### Initialize Winsock:
- `if (WSAStartup(MAKEWORD(2,2), &wsa) != 0) {...}`: Calls `WSAStartup` to initialize Winsock. If it fails, prints an error message and returns `1`.

### Print Success Message:
- `printf("Initialized.\n");`: Prints a success message if Winsock initialization is successful.

###  Create a Socket:
- `if ((socketDescriptor = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET) {...}`: Creates a socket for IPv4 and TCP. If socket creation fails, prints an error message.

###  Print Success Message:
- `printf("Socket created.\n");`: Prints a success message if the socket is successfully