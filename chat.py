#SERVER.PY

import socket
server = socket.socket()
server.bind(('',12345))
print("Socket is created successfully")
server.listen()
print("Waiting for Connection...")
c,addr = server.accept()
print("Got a connection from ",addr)
while(True):
    clientmsg = c.recv(1024).decode()
    if(clientmsg!="quit"):
        print("Client:",clientmsg)
        msg = input("Server: ")
        c.send(msg.encode())
    else:
        c.close()
        server.close()
        break

#CLIENT.PY

import socket
client = socket.socket()
client.connect(('localhost',12345))
print("Connection Established!")
while True:
    msg = input("Client: ")
    if(msg!="quit"):
        client.send(msg.encode())
        print("Server:",client.recv(1024).decode())
    else:
        client.send("quit".encode())
        client.close()
        break
