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

#define RCVBUFSIZE 32 // size of receive buffer

void DieWithError(char *errorMessage); //error handling function

int main(int argc, char *argv[]){
    int sock;                           // socket descriptor
    struct sockaddr_in echoServAddr;
    unsigned short echoServPort;
    char *servIP;                       // dotted quad (x.x.x.x)
    char *echoString;                    // string to send to ip server
    char echoBuffer[RCVBUFSIZE];        // buffer for echo string
    unsigned int echoStringLen; 
    int bytesRcvd, totalBytesRcvd;

    // check for the right amount of inputs
    if ((argc < 3) || (argc > 4)){
        fprintf(stderr, "Usage: %s <Server IP> <Echo Word> [<Echo Port>] \n", argv[0]);
        exit(1);
    }

    servIP = argv[1];
    echoString = argv[2];

    if (argc == 4) 
        echoServPort = atoi(argv[3]);
    else 
        echoServPort = 7; // 7 is a well known port for the echo service
    
    // create a reliable steam socket using TCP
    if ((sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP) < 0))
        DieWithError("socket() failed");
    
    // construct server address structure
    memset(&echoServAddr, 0, sizeof(echoServAddr));
    echoServAddr.sin_family = AF_INET;
    echoServAddr.sin_addr.s_addr = inet_addr(servIP);
    echoServAddr.sin_port = htons(echoServPort);

    // establish a connection to the echo server
    if (connect(sock, (struct sockaddr *) &echoServAddr, sizeof(echoServAddr)) < 0)
        DieWithError("connect() failed");

    echoStringLen = strlen(echoString);
    
    // send the string to the server
    if (send(sock, echoString, echoStringLen, 0) != echoStringLen)
        DieWithError("send() sent a different number of bytes than expected");
    
    // receive the same string back from the server
    totalBytesRcvd = 0;
    bytesRcvd = 0;
    printf("%d",totalBytesRcvd);
    printf("Received: ");
    while (bytesRcvd < echoStringLen) {
        // receive up to the buffer size - 1 (for null terminator) bytes from the sender
        if ((bytesRcvd = recv(sock, echoBuffer, RCVBUFSIZE -1, 0)) <= 0)
            DieWithError("recv() failed or connection closed prematurely");
        totalBytesRcvd += bytesRcvd;
        echoBuffer[bytesRcvd] = '\0';
        printf("%s", echoBuffer);
    }

    printf("\n");   // print a final linefeed

    close(sock);
    exit(0);
}