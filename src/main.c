#include <stdio.h>
#include <unistd.h>
#include <arpa/inet.h>
#include "socket.h"
#include "client.h"
#include "logger.h"

int main() {
    int server_fd = create_server_socket(8080);

    // printf("Server is ready...\n");
    log_info("Server is ready...");
    
    while (1) {
        int client_fd = accept(server_fd, NULL, NULL);

        if (client_fd < 0) {
            perror("accept failed");
            continue;
        }

        printf("Client connected!\n");

        handle_client(client_fd);
    }

    close(server_fd);
    return 0;
}