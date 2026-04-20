#include "mime.h"
#include <string.h>
//File type identifier
//Given a file → what type is it?
const char* get_mime_type(const char *path) {

    if (strstr(path, ".html")) return "text/html";
    if (strstr(path, ".css")) return "text/css";
    if (strstr(path, ".js")) return "application/javascript";
    if (strstr(path, ".png")) return "image/png";
    if (strstr(path, ".jpg")) return "image/jpeg";

    return "text/plain";
}