import socket

# Client setup
client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
client_socket.connect(('localhost', 8888))  # Connect to the server

message = "Hi Indira!"
client_socket.sendall(message.encode())

data = client_socket.recv(1024)  # Receive the echoed message
print(f"Received from server: {data.decode()}")

client_socket.close()  # Close the connection
