#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 12345
#define SERVER_IP "127.0.0.1"

int main() {
    int client_socket;
    struct sockaddr_in server_address;
    char message[] = "Hello from C client!";

    // Create socket
    if ((client_socket = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Initialize server address structure
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = inet_addr(SERVER_IP);
    server_address.sin_port = htons(PORT);

    // Connect to the server
    if (connect(client_socket, (const struct sockaddr*)&server_address, sizeof(server_address)) == -1) {
        perror("Connection failed");
        close(client_socket);
        exit(EXIT_FAILURE);
    }

    // Send data to the server
    ssize_t sent_bytes = send(client_socket, message, strlen(message), 0);

    if (sent_bytes == -1) {
        perror("Send failed");
        close(client_socket);
        exit(EXIT_FAILURE);
    }

    printf("Message sent to server: %s\n", message);

    // Close the socket
    close(client_socket);

    return 0;
}
