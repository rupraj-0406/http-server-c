#include "router.h"
#include <string.h>
#include <unistd.h>

void route_request(int client_fd, HttpRequest *req)
{

    if (strcmp(req->method, "GET") == 0 && strcmp(req->path, "/") == 0)
    {

        char *response =
            "HTTP/1.1 200 OK\r\n"
            "Content-Type: text/plain\r\n\r\n"
            "Welcome to home page";

        send(client_fd, response, strlen(response), 0);
    }

    else if (strcmp(req->method, "GET") == 0 && strcmp(req->path, "/hello") == 0)
    {

        char *response =
            "HTTP/1.1 200 OK\r\n"
            "Content-Type: text/plain\r\n\r\n"
            "Hello route working!";

        send(client_fd, response, strlen(response), 0);
    }
    else if (strcmp(req->method, "POST") == 0 && strcmp(req->path, "/data") == 0)
    {

        char response[4096];

        sprintf(response,
                "HTTP/1.1 200 OK\r\n"
                "Content-Type: text/plain\r\n\r\n"
                "Received data: %s",
                req->body);

        send(client_fd, response, strlen(response), 0);
    }
    else if (strcmp(req->method, "DELETE") == 0 && strcmp(req->path, "/data") == 0)
    {

        char *response =
            "HTTP/1.1 200 OK\r\n"
            "Content-Type: text/plain\r\n\r\n"
            "Data deleted successfully";

        send(client_fd, response, strlen(response), 0);
    }
    else if (strcmp(req->method, "PATCH") == 0 && strcmp(req->path, "/data") == 0)
    {

        char response[4096];

        sprintf(response,
                "HTTP/1.1 200 OK\r\n"
                "Content-Type: text/plain\r\n\r\n"
                "Updated data: %s",
                req->body);

        send(client_fd, response, strlen(response), 0);
    }
    else if (strcmp(req->method, "HEAD") == 0)
    {

        char *response =
            "HTTP/1.1 200 OK\r\n"
            "Content-Type: text/plain\r\n\r\n";

        send(client_fd, response, strlen(response), 0);
    }
    else
    {

        char *response =
            "HTTP/1.1 404 Not Found\r\n"
            "Content-Type: text/plain\r\n\r\n"
            "Route not found";

        send(client_fd, response, strlen(response), 0);
    }
}