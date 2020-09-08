#include <stdio.h>
#include "../http/server.h"
#include "../lib/string.h"
#include "../lib/std.h"

// Simple macro for locally checking a command arg for this cli element.
#define CHECK_ARG(short_arg, long_arg) str_equals(command[command_ptr], short_arg) || str_equals(command[command_ptr], long_arg)

/**
 * Print the help menu for the SQS CLI
 */
void print_sqs_help() {
    printf("Commands related to the clone SQS service.\n");
    printf("\n");
    printf("help\tShow this message.\n");
    printf("start\tStart the SQS server.\n");
    printf("\t\t-p/--port\tPort for the SQS server.\n");
    printf("\t\t-b/--backlog\tConnection queue backlog max length.\n");
    printf("stop\tStop the SQS server.\n");
    printf("\n");
}

/**
 * Process commands for SQS CLI 
 */
int process_sqs_command(int commandc, char** command) {
    // Decide what to do based on the given command.
    if (str_equals(command[0], "help")) print_sqs_help();
    else if (str_equals(command[0], "start")) {
        // Give defaults to the different args
        int port = 8080;
        int backlog_len = 10;
        int command_ptr = 0;

        // Process args as given
        while (command_ptr < commandc) {
            if (CHECK_ARG("-p", "--port")) {
                if (command_ptr + 1 >= commandc) {
                    printf("No argument given for -p/--port.\n");
                    return 0;
                }

                port = atoi(command[++command_ptr]);
            } else if (CHECK_ARG("-b", "--backlog")) {
                if (command_ptr + 1 >= commandc) {
                    printf("No argument give for -b/--backlog.\n");
                    return 0;
                }

                backlog_len = atoi(command[++command_ptr]);
            }

            command_ptr ++;
        }

        return launch_server(port, backlog_len);
    }
    else print_sqs_help();
    
    return 1;
}
