#ifndef PARSER_H
#define PARSER_H

typedef struct {
    char method[10];
    char path[100];
    char body[2048];
} HttpRequest;

void parse_request(char *buffer, HttpRequest *req);

#endif