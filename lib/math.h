/** 
 * Calculate a generic power function.
*/
float mpow(float base, float exponent) {
    // Cover some base cases
    if (base == 0) return 0;
    if (exponent == 0) return 1;
    
    // Calculate the result
    float result = 1;
    while (exponent > 0) {
        result *= base;
        exponent--;
    }
    
    // If the exponent is negative, flip
    if (exponent < 0) return 1 / result;

    return result;
}

/** 
 * Get the greatest common divisor of two
 * integers using Euclid's method.
*/
int euclid_gcd(int m, int n) {

    // If m < n, swap them to save an iteration
    if (m < n) {
        int temp = m;
        m = n;
        n = temp;
    }

    // Float division to get the remainder.
    int r = m % n;
    while (r != 0) {
        m = n;
        n = r;
        r = m % n;
    }

    return n;
}
