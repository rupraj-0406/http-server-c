#include <stdio.h>
#include <unistd.h>
#include <arpa/inet.h>
#include "socket.h"
#include "client.h"
#include "logger.h"

int main() {
    int server_fd = create_server_socket(8080);
    // server_fd->listening socket
    // create_server_socket(), calls function from socket.c (socket(),bind(),listen())

    // printf("Server is ready...\n");
    log_info("Server is ready...");
    // inside logger.c
    
    while (1) {
        int client_fd = accept(server_fd, NULL, NULL);
        // client_fd->communication socket
        // accept client, waits for connection

        if (client_fd < 0) {
            perror("accept failed");
            continue;
        }
        // error handling, print error & skip iteration

        printf("Client connected!\n");

        handle_client(client_fd);
        // control goes to client.c
    }

    close(server_fd);
    return 0;
}