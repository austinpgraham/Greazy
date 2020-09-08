#ifndef REQUEST_H
#define REQUEST_H
#include <stdio.h>
#include "../lib/string.h"

/**
 * Generates an appropriate HTTP response for REST API services.
 */
void generate_response(char* response, int status_code, char* content, char* content_type_header) {
    char* message;
    if (status_code == 200) message = "OK";
    else {
        status_code = 500;
        message = "INTERNAL SERVER ERROR";
    }

    sprintf(response, "HTTP/1.1 %d %s\nContent-Type: %s\nContent-Length: %d\n\n%s", status_code, message, content_type_header, str_len(content), content);
}

#endif
