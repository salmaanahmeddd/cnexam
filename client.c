#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 12345
#define BUFFER_SIZE 1024

int main() {
    int server_socket;
    struct sockaddr_in server_address, client_address;
    socklen_t client_address_len = sizeof(client_address);
    char buffer[BUFFER_SIZE];

    // Create UDP socket
    if ((server_socket = socket(AF_INET, SOCK_DGRAM, 0)) == -1) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Initialize server address structure
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    // Bind the socket
    if (bind(server_socket, (struct sockaddr*)&server_address, sizeof(server_address)) == -1) {
        perror("Bind failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d...\n", PORT);

    // Receive data from the client
    ssize_t received_bytes = recvfrom(server_socket, buffer, sizeof(buffer), 0,
                                      (struct sockaddr*)&client_address, &client_address_len);

    if (received_bytes == -1) {
        perror("Receive failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    buffer[received_bytes] = '\0'; // Null-terminate the received data

    printf("Received from client: %s\n", buffer);

    // Close the socket
    close(server_socket);

    return 0;
}
