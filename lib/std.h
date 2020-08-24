#include <stddef.h>
#include "math.h"

// A few useful ASCII contants;
#define ASCII_0 48
#define ASCII_9 57

/** 
 * Returns the length of the given string.
 * 
 * "Austin Graham" -> 13
*/
int str_len(char* str) {
    int result = 0;
    
    // Return 0 if there is no string
    if (str == NULL || str[0] == '\0') return result;

    // Increment while we haven't reached the null terminator
    char ptr = 0;
    while (str[ptr++] != '\0') result++;

    return result;
}

/** 
 * Simple implementation of a function converting
 * a string to an integer.
 * 
 * Takes as input a string representing an integer.
 * If the given input is not an integer, then an
 * error is thrown.
 * 
 * "1234" -> 1234
*/
int atoi (char* str) {
    int result = 0;

    // Get the length of the string and check
    int length = str_len(str);
    if (length == 0) return 0;
    
    // Iterate over the string backwards to get the result
    int ptr = length - 1;
    while (ptr >= 0) {
        char ptr_char = str[ptr];

        // Use the ASCII value to get the numeric value.
        // At this point, we can check if it is a valid number. If not,
        // then we throw an error
        int adjusted_ascii = ptr_char - ASCII_0;

        // If invalid, return an error value
        if (adjusted_ascii < 0 || adjusted_ascii > 9) return 0;

        // Otherwise, add to the result
        result += adjusted_ascii * (int)mpow(10, length - ptr - 1);

        ptr--;
    }

    return result;
}
