#ifndef SERVER_H
#define SERVER_H
#include <stdio.h>
#include <unistd.h> 
#include <sys/socket.h> 
#include <netinet/in.h>
#include "request.h"
#include "../lib/string.h"

#define MAX_REQUEST_LENGTH 1024

int launch_server(int port, int backlog_len) {
    int server_fd;

    // Create the socket file descriptor, return error
    // if necessary.
    //
    // First arg AF_INET indicates use of IPv4, use AF_INET6 for IPv6.
    // Second arg SOCK_STREAM indicates TCP, use SOCK_DGRAM for a UDP connection.
    // We're looking to create a REST server, so of course use TCP
    // Third arg is the protocol header for use in packets, always use 0
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        printf("Failed to create socket descriptor.\n");
        return 0;
    }

    // Now we bind the address to the given port.
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(port);
    if (bind(server_fd, (struct sockaddr*)&address, sizeof(address))<0) {
        printf("Failed to bind server to given address. Is the address already in use?\n");
        return 0;
    }

    // Listen on the socket for so many given connections
    if(listen(server_fd, backlog_len)) {
        printf("Failed to listen on SQS socket.\n");
        return 0;
    }

    // Run the server...
    printf("SQS server started on port %d\n", port);
    while (1) {
        // accept the next connection.
        int next_connection = accept(server_fd, (struct sockaddr*)&address, (socklen_t*)&addrlen);

        // uh oh, we have a bad connection.
        if (next_connection < 0) {
            printf("Failed to accept connection request.\n");
            continue;
        }

        // Get the data of the request
        char buffer[MAX_REQUEST_LENGTH];
        int bytes_read = read(next_connection, buffer, MAX_REQUEST_LENGTH);
        printf("Read %d bytes: %s.\n", bytes_read, buffer);

        // Process the connection request
        char response_message [1000];
        generate_response(response_message, 200, "Got it!", "text/plain");
        send(next_connection, response_message, str_len(response_message), 0);
    } 

    // We are successfully launched
    return 1;
}
#endif
