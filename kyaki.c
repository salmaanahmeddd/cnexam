import socket
import os
server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server.bind(("127.0.0.1", 12345))
server.listen(5)
print("Server listening...")
while True:
 client, address = server.accept()
 print(f"Connection from {address} established.")
 # Specify the file name here
 file_name = "file1.txt"
 with open(file_name, "rb") as file:
 # Send the file name to the client
 client.send(file_name.encode())
 # Send the file content to the client
 client.sendfile(file)
 print("File transfer complete.")
 client.close()
client.py
import socket
client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
client.connect(("127.0.0.1", 12345))
# Receive the file name from the server
file_name = client.recv(1024).decode()
print(f"Downloading file: {file_name}")
with open("client_file.txt", "wb") as file:
 # Receive and write the file content
 file.write(client.recv(1024))
print("File download complete.")
client.close()
