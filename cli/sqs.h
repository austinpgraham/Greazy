#include <stdio.h>
#include "../http/server.h"
#include "../lib/string.h"

void print_sqs_help() {
    printf("Commands related to the clone SQS service.\n");
    printf("\n");
    printf("help\tShow this message.\n");
    printf("start\tStart the SQS server.\n");
    printf("stop\tStop the SQS server.\n");
    printf("\n");
}

int process_sqs_command(char** command) {
    // Decide what to do based on the given command.
    if (str_equals(command[0], "help")) print_sqs_help();
    else if (str_equals(command[0], "start")) {
        return launch_server(8080, 10);
    }
    else print_sqs_help();
    
    return 1;
}
