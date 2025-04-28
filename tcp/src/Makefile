all: TCPEchoServer TCPEchoClient

TCPEchoServer: TCPEchoServer.o DieWithError.o HandleTCPClient.o
	clang TCPEchoServer.o DieWithError.o HandleTCPClient.o -o TCPEchoServer

TCPEchoClient: TCPEchoClient.o DieWithError.o
	clang TCPEchoClient.o DieWithError.o -o TCPEchoClient

HandleTCPClient.o: HandleTCPClient.c
	clang -c HandleTCPClient.c

TCPEchoClient.o: TCPEchoClient.c
	clang -c TCPEchoClient.c

TCPEchoServer.o: TCPEchoServer.c
	clang -c TCPEchoServer.c

DieWithError.o: DieWithError.c
	clang -c DieWithError.c

clean:
	rm -f TCPEchoClient.o TCPEchoServer.o  HandleTCPClient.o DieWithError.o TCPEchoClient TCPEchoServer

