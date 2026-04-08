#include "router.h"
#include "file_handler.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>

void route_request(int client_fd, HttpRequest *req)
{
    // 🔥 HOME
    if (strcmp(req->method, "GET") == 0 && strcmp(req->path, "/") == 0)
    {
        char file_path[256];
        sprintf(file_path, "www/index.html");
        serve_file(client_fd, file_path);
    }

    // 🔥 HELLO ROUTE
    else if (strcmp(req->method, "GET") == 0 && strcmp(req->path, "/hello") == 0)
    {
        char *response =
            "HTTP/1.1 200 OK\r\n"
            "Content-Type: text/plain\r\n\r\n"
            "Hello route working!";

        send(client_fd, response, strlen(response), 0);
    }

    // 🔥 GET DATA (DATABASE READ)
    else if (strcmp(req->method, "GET") == 0 && strcmp(req->path, "/data") == 0)
    {
        FILE *file = fopen("data.txt", "r");
        char buffer[4096] = {0};

        if (file)
        {
            fread(buffer, 1, sizeof(buffer), file);
            fclose(file);
        }

        char response[5000];

        sprintf(response,
                "HTTP/1.1 200 OK\r\n"
                "Content-Type: text/plain\r\n\r\n%s",
                buffer);

        send(client_fd, response, strlen(response), 0);
    }

    // 🔥 POST (CREATE)
    else if (strcmp(req->method, "POST") == 0 && strcmp(req->path, "/data") == 0)
    {
        FILE *file = fopen("data.txt", "a");

        if (file)
        {
            fprintf(file, "%s\n", req->body);
            fclose(file);
        }

        char *response =
            "HTTP/1.1 200 OK\r\n"
            "Content-Type: text/plain\r\n\r\n"
            "Data stored successfully";

        send(client_fd, response, strlen(response), 0);
    }

    // 🔥 DELETE (CLEAR)
    else if (strcmp(req->method, "DELETE") == 0 && strcmp(req->path, "/data") == 0)
    {
        FILE *file = fopen("data.txt", "w");
        if (file) fclose(file);

        char *response =
            "HTTP/1.1 200 OK\r\n"
            "Content-Type: text/plain\r\n\r\n"
            "Data deleted successfully";

        send(client_fd, response, strlen(response), 0);
    }

    // 🔥 PATCH (UPDATE)
    else if (strcmp(req->method, "PATCH") == 0 && strcmp(req->path, "/data") == 0)
    {
        FILE *file = fopen("data.txt", "w");

        if (file)
        {
            fprintf(file, "%s\n", req->body);
            fclose(file);
        }

        char response[4096];

        sprintf(response,
                "HTTP/1.1 200 OK\r\n"
                "Content-Type: text/plain\r\n\r\n"
                "Data updated");

        send(client_fd, response, strlen(response), 0);
    }

    // 🔥 HEAD
    else if (strcmp(req->method, "HEAD") == 0)
    {
        char *response =
            "HTTP/1.1 200 OK\r\n"
            "Content-Type: text/plain\r\n\r\n";

        send(client_fd, response, strlen(response), 0);
    }

    // 🔥 STATIC FILES (KEEP LAST)
    else if (strcmp(req->method, "GET") == 0)
    {
        char file_path[256];
        sprintf(file_path, "www%s", req->path);
        serve_file(client_fd, file_path);
    }

    // 🔥 DEFAULT
    else
    {
        char *response =
            "HTTP/1.1 404 Not Found\r\n"
            "Content-Type: text/plain\r\n\r\n"
            "Route not found";

        send(client_fd, response, strlen(response), 0);
    }
}