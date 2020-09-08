#include "sqs.h"
#include "../lib/string.h"

/**
 * Simply prints the help messages.
 */
void print_help() {
    printf("\n");
    printf("Welcome to the open source cloud service!\n");
    printf("\n");
    printf("-h\tPrint this message");
    printf("\n\n");
    printf("Use the following subcommands to access the difference resources:\n\n");
    printf("sqs\tThe SQS clone service.\n\n");
}


/**
 * Entry point for the primary CLI.
 * 
 * Written originally by Austin Graham...we'll
 * see if this really goes anywhere.
 */

int main(int argc, char** argv) {

    // If we don't have enough arguments, just
    // print the hepl message.
    if (argc < 2 || str_equals(argv[1], "-h")) {
        print_help();
        return -1;
    }

    // Determine what to do based on the command given.
    char* service_arg = argv[1];
    if (str_equals(service_arg, "sqs")) process_sqs_command(argv[2]);
    else {

        // If we don't recognize the command, then print the
        // help and return an error code.
        print_help();
        return -1;
    }

    return 0;
}
