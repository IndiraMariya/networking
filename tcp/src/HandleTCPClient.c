#include <stdio.h>      //for printf
#include <sys/socket.h> //for socket(), connect(), recv()
#include <arpa/inet.h>  //for sockaddr_in() and inet_addr()

#define RCVBUFSIZE 32

void DieWithError(char *errorMessage);      // error handling 
void close(int socket);

void HandleTCPClient(int clntSocket) {
    char echoBuffer[RCVBUFSIZE];
    int recvMsgSize;

    if ((recvMsgSize = recv(clntSocket, echoBuffer, RCVBUFSIZE, 0)) < 0)
        DieWithError("recv() failed");
    
        while (recvMsgSize > 0) {
            if (send(clntSocket, echoBuffer, recvMsgSize, 0) != recvMsgSize)
                DieWithError("send() failed");
            
            if ((recvMsgSize = recv(clntSocket, echoBuffer, RCVBUFSIZE, 0)) < 0)
                DieWithError("recv() failed");
        }

    close(clntSocket);
}