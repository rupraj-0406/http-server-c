#include "file_handler.h"
#include "mime.h"
#include<string.h>
#include <stdio.h>
#include <unistd.h>

void serve_file(int client_fd, const char *path)
{   // router → file_handler → send file
    //client_fd → where to send
    //path → which file to send
    FILE *file = fopen(path, "r");

    if (!file)
    {
        char *response =
            "HTTP/1.1 404 Not Found\r\n\r\nFile not found";
        write(client_fd, response, strlen(response));
        return;
    }

    char buffer[4096];
    fread(buffer, 1, sizeof(buffer), file);
    //read file into memory

    const char *mime = get_mime_type(path);
    //decide file type
    //index.html → text/html
    //style.css  → text/css
    //without mime browser wont render properly
    //MIME = telling the browser what type of file you sent
    //e.g. 
    //Content-Type: text/html
    //browser: "Render this as a webpage"
    //e.g.
    //Content-Type: text/plain
    //browser: "Show raw text"
    //MIME type tells the client how to interpret the response data. i.e. adding label

    char header[256];

    sprintf(header,
            "HTTP/1.1 200 OK\r\n"
            "Content-Type: %s\r\n\r\n",
            mime);
            /*
                HTTP/1.1 200 OK  → status
                Content-Type     → file type
                \r\n\r\n         → end of header
            */

    write(client_fd, header, strlen(header));
    write(client_fd, buffer, strlen(buffer));
    //first send metadata
    //then send content

    fclose(file);
}
// The file handler opens the requested file, 
// reads its contents into a buffer, 
// determines the MIME type, 
// constructs an HTTP response header, 
// and sends both the header and file content to the client.