#SERVER.PY

import socket
server = socket.socket()
port = 12345
server.bind(('',port))
server.listen()
print("Server islistening...")
c,addr = server.accept()
print("Got Connection from ",addr)
while(True):
    data = c.recv(1024)
    msg = data.decode()
    if(msg!="quit"):
        print("Recieved:",msg)
        c.sendall(data)
    else:
        c.close()
        server.close()
        break

#CLIENT.PY

import socket
client = socket.socket()
client.connect(("localhost",12345))
print("Connection Established! ")
while(True):
    msg = input("Client: ")
    client.sendall(msg.encode())
    if(msg!='quit'):
        data = client.recv(1024).decode()
        print("Server:",data)
    else:
        client.send('quit'.encode())
        client.close()
        break
