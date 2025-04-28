import socket

# Server setup
server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server_socket.bind(('localhost', 8888))  # Bind to the localhost and port 12345
server_socket.listen(5)  # Listen for up to 5 connections

print("Server listening on port 8888...")

while True:
    client_socket, client_address = server_socket.accept()  # Accept a connection
    print(f"Connection from {client_address} has been established.")
    
    data = client_socket.recv(1024)  # Receive data (up to 1024 bytes)
    
    if data:
        print(f"Received message: {data.decode()}")
        client_socket.sendall(data)  # Send the same data back (echo)
        client_socket.close()  # Close the client connection
