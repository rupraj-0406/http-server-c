#include "socket.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
//Creating the network system
// Create → Bind → Listen
int create_server_socket(int port) {
//     i/p  → port (8080)
//     o/p → server_fd (socket descriptor)
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    //Creating a network line
        // AF_INET     → IPv4
        // SOCK_STREAM → TCP
        // 0           → default protocol

    if (server_fd < 0) {
        perror("socket failed");
        exit(1);
    }

    // 🔥 allow reuse of port
    int opt = 1;
    setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    struct sockaddr_in address;

    address.sin_family = AF_INET; //IPv4 addressing
    address.sin_addr.s_addr = INADDR_ANY; //Accept connections from ANY IP
    address.sin_port = htons(port); //Host TO Network Short

    // 🔥 bind
    if (bind(server_fd, (struct sockaddr*)&address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(1);
    }
    //Attach socket → specific port

    // 🔥 listen
    if (listen(server_fd, 10) < 0) {
        perror("listen failed");
        exit(1);
    }
    //Start waiting for connections
    //Backlog queue size(max pending connections) is 10 here

    printf("Server listening on port %d\n", port);

    return server_fd;
}

// socket() → create endpoint
    //server_fd = integer
    // 0 → stdin
    // 1 → stdout
    // 2 → stderr
    // 3+ → sockets/files
// bind()   → assign port
// listen() → wait for clients
// return   → ready to accept