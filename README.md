# Echo Server-Client in Python

This repository contains a simple **Echo Server-Client** application in Python. The server listens for incoming connections and echoes back any message received from a client. The client connects to the server using a specified IP address and port.

## Requirements

- Python 3.x (no external libraries needed)

## Usage

### Server

1. Run the server script:
   ```bash
   python echo_server.py

## Client
1. Run the client script:

``` bash
python echo_client.py
```
2. Enter the IP address and port of the server when prompted.

## Example
* Server Output:

``` bash
Server listening on port 12345...
Connection from ('127.0.0.1', 56789) has been established.
Received message: Hello, Echo Server!
```
* Client Output:

``` bash
Enter the server IP address: 127.0.0.1
Enter the port number: 12345
Received from server: Hello, Echo Server!
```
## License
[MIT LICENSE](LICENSE)