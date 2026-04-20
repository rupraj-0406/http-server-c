#include "logger.h"
#include <stdio.h>
#include <time.h>
//server history
//keep record of=>
//  1. when server starts
//  2. what requests come
//  3. what users are doing

void log_info(const char *message) {
    time_t now = time(NULL);
    struct tm *t = localtime(&now);

    printf("[INFO] %04d-%02d-%02d %02d:%02d:%02d - %s\n",
        t->tm_year + 1900, t->tm_mon + 1, t->tm_mday,
        t->tm_hour, t->tm_min, t->tm_sec,
        message);
}

void log_request(const char *method, const char *path) {
    time_t now = time(NULL);
    struct tm *t = localtime(&now);

    printf("[REQUEST] %04d-%02d-%02d %02d:%02d:%02d - %s %s\n",
        t->tm_year + 1900, t->tm_mon + 1, t->tm_mday,
        t->tm_hour, t->tm_min, t->tm_sec,
        method, path);
}