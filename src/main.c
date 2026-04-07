#include <stdio.h>
#include "socket.h"

int main() {
    int server_fd = create_server_socket(8080);

    printf("Socket created successfully: %d\n", server_fd);

    return 0;
}
