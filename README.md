# TCP Echo Server-Client in C

This repository contains a simple **Echo Server-Client** application in Python. The server listens for incoming connections and echoes back any message received from a client. The client connects to the server using a specified IP address and port.

## Requirements

### Libraries:
* sys/socket.h (for socket-related functions)
* arpa/inet.h (for manipulating IP addresses and network protocols)
* stdio.h (for input/output operations)
* stdlib.h (for memory allocation and program termination)
* string.h (for string manipulation)
* unistd.h (for POSIX functionalities like close())

## Usage
>**Tip:** use 1024 as your port to use the default http port.

### Server

1. Run the server script:
   ```bash
   ./TCPEchoServer <PORT>
   ```

## Client
1. In a new terminal run the client script: 
   ``` bash
   ./TCPEchoClient <IP_ADDRESS> <MESSAGE> <PORT>
   ```

   

## Example
* Client Input
   ```bash 
   ./TCPEchoClient 127.0.0.1 "Hello TCP"
   ```


* Server Output:

   ```
   1) Server socket creation succeeded.
   2) Socket bind() succeeded.
   3) Listening for clients.
   Waiting for client...
   ```
* Client Output:

   ```
   1) Client socket creation succeeded.
   2) Socket connected to server.
   3) Sent Bytes: 9
   4) Received string: Hello TCP
   ```
## License
[MIT LICENSE](LICENSE)