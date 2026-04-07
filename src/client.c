#include "client.h"
#include <stdio.h>
#include <unistd.h>
#include <string.h>

void handle_client(int client_fd) {
    char buffer[4096] = {0};

    read(client_fd, buffer, sizeof(buffer));

    printf("Request received:\n%s\n", buffer);

    char *response =
        "HTTP/1.1 200 OK\r\n"
        "Content-Type: text/plain\r\n"
        "\r\n"
        "Hello from modular C server!";

    send(client_fd, response, strlen(response), 0);

    close(client_fd);
}