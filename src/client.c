#include "client.h"
#include "parser.h"
#include "router.h"
#include "logger.h"
#include <stdio.h>
#include <unistd.h>

void handle_client(int client_fd) {
    char buffer[4096] = {0};

    read(client_fd, buffer, sizeof(buffer));

    printf("Raw Request:\n%s\n", buffer);

    HttpRequest req;
    parse_request(buffer, &req);
    log_request(req.method, req.path);
    printf("Method: %s, Path: %s\n", req.method, req.path);
    printf("Body: %s\n", req.body);
    route_request(client_fd, &req);

    close(client_fd);
}