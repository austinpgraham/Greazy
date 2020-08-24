#include <stdio.h>
#include "../lib/std.h"

/**
 * Given two numbers, calculates the Greatest Common Divisor
 * between the two numbers use Euclid's algorithm.
*/
int main(int argc, char** argv) {

    // Check valid arguments
    if (argc < 3) {
        printf("Invalid number of arguments given.\n");
        return -1;
    }

    // Get the integer values from the arguments
    int m = atoi(argv[1]);
    int n = atoi(argv[2]);
    
    // Get the result
    int gcd = euclid_gcd(m, n);
    printf("The GCD between %d and %d is: %d\n", m, n, gcd);

    return 0;
}
