#include <stdio.h>

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
 * Returns an array of strings tokenized by the given split char.
 * So far unimplemented.
 * 
 * "Austin Graham is cool" -> ["Austin", "Graham", "is", "cool"]
 */
char** str_tok(char* str, char split) {
    return NULL;
}

/**
 * Determine if two strings are equal.
 * 
 * "Austin", "graham" -> false
 * "Austin", "Austin" -> false
 */
int str_equals(char* str_one, char* str_two) {
    
    // A couple of base cases to cover null pointers
    // that may or may not be passed
    if (str_one == NULL && str_two == NULL) return 1;
    if ((str_one == NULL && str_two != NULL) || (str_one != NULL && str_two == NULL)) return 0;

    // If we're here, nothing is NULL and
    // we can effectively compare
    int ptr_one = 0;
    int ptr_two = 0;

    while (str_one[ptr_one] != '\0' && str_two[ptr_two] != '\0') {
        
        // Return false on first instance where they are not equal
        if (str_one[ptr_one] != str_two[ptr_two]) return 0;

        // Otherwise, increment the pointers
        ptr_one ++;
        ptr_two ++;
    }

    // If we cover both strings, then they're equal
    return 1;
}
