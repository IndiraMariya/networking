/*
5/27/25
From example in chapter 2.3 of TCP/IP Sockets by Michael J. Donahoo and Kenneth L. Calvert
*/

#include <stdio.h>      //for printf
#include <sys/socket.h> //for socket(), connect(), recv()
#include <arpa/inet.h>  //for sockaddr_in() and inet_addr()
#include <stdlib.h>     // for atoi()
#include <string.h>     // for memset()
#include <unistd.h>     // for close()

#define MAXPENDING 5    //maximum outstanding connection requests

void DieWithError(char *errorMessage);      // error handling 
void HandleTCPClient(int clntSocket);       // TCP client handling function

int main(int argc, char *argv[]) {
    int servSock;
    int clntSock;
    struct sockaddr_in echoServAddr;
    struct sockaddr_in echoClntAddr;
    unsigned short echoServPort;
    unsigned int clntLen;

    if (argc !=2 ) {
        fprintf(stderr, "Usage: %s <Server Port>\n", argv[0]);
        exit(1);
    }

    echoServPort = atoi(argv[1]);
    if ((servSock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0) {
        DieWithError("socket() failed");
    }
    printf("1) Server socket creation succeeded.\n");

    memset(&echoServAddr, 0, sizeof(echoServAddr));
    echoServAddr.sin_family = AF_INET;
    echoServAddr.sin_addr.s_addr = htonl(INADDR_ANY);
    echoServAddr.sin_port = htons(echoServPort);

    if(bind(servSock, (struct sockaddr *) &echoServAddr, sizeof(echoServAddr)) < 0)
        DieWithError("bind() failed");
    printf("2) Socket bind() succeeded.\n");
    
    if (listen(servSock, MAXPENDING) < 0)
        DieWithError("listen() failed");
    printf("3) Listening for clients.\n");
    
    for(;;) {
        printf("Waiting for client... \n");
        clntLen = sizeof(echoClntAddr);
        if((clntSock = accept(servSock, (struct sockaddr * ) &echoClntAddr, &clntLen) )< 0)
            DieWithError("accept() failed");
        
        printf("Handling client %s \n", inet_ntoa(echoClntAddr.sin_addr));
        HandleTCPClient(clntSock);
    }
} 