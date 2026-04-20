#include "client.h"
#include "parser.h"
#include "router.h"
#include "logger.h"
#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>

void handle_client(int client_fd) {
    char buffer[4096] = {0};

    read(client_fd, buffer, sizeof(buffer));
    // Reads data from client into buffer
    // read() = "hearing what client says"
    /*
    e.g:
        stored in buffer
        "GET /data HTTP/1.1
        Host: localhost"
    
    */ 

    printf("Raw Request:\n%s\n", buffer);
    // Shows full HTTP request

    HttpRequest req;
    // create request structure, struct define in parser.h
    /*

        typedef struct {
            char method[10];
            char path[100];
            char body[2048];
        } HttpRequest;
         e.g.
            method → GET/POST
            path   → /data
            body   → name=abc
    */ 
    parse_request(buffer, &req);
    // Converts raw text → structured data
    // before: "POST /data HTTP/1.1..."
    /*
        req.method = "POST"
        req.path   = "/data"
        req.body   = "name=abc"
    */ 
    //    Parser = understanding language
    log_request(req.method, req.path);
    printf("Method: %s, Path: %s\n", req.method, req.path);
    printf("Body: %s\n", req.body);
    route_request(client_fd, &req);
    // Control goes to router.c

    close(client_fd);
    // End communication
}