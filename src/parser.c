#include "parser.h"
#include <stdio.h>
#include <string.h>

void parse_request(char *buffer, HttpRequest *req) {
    sscanf(buffer, "%s %s", req->method, req->path);

    char *body_start = strstr(buffer, "\r\n\r\n");
    if (body_start != NULL) {
        body_start += 4;  // skip delimiter
        strcpy(req->body, body_start);
    } else {
        req->body[0] = '\0';
    }
}