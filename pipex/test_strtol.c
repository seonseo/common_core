#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <limits.h>
#include "libft/libft.h"  // Ensure this contains the declaration for ft_strtol()

void test_strtol(const char *str, int base) {
    char *endptr;
    char *ft_endptr;
    long val;
    long ft_val;

    // Reset errno to 0 before the call to detect changes set by strtol
    errno = 0;
    val = strtol(str, &endptr, base);

    int errno_std = errno;  // Capture errno set by strtol

    // Reset errno to 0 before the call to detect changes set by ft_strtol
    errno = 0;
    ft_val = ft_strtol(str, &ft_endptr, base);

    int errno_ft = errno;  // Capture errno set by ft_strtol

    printf("strtol:    %ld, errno: %d, Remaining: '%s'\n", val, errno_std, endptr);
    printf("ft_strtol: %ld, errno: %d, Remaining: '%s'\n", ft_val, errno_ft, ft_endptr);
    printf("---------------------------------------------------\n");
}

int main(void) {
    test_strtol("123", 10);
    test_strtol("abcdef", 16);
    test_strtol("0777", 0);
    test_strtol("0x1a3f", 0);
    test_strtol("123xyz", 10);
    test_strtol("2147483647", 10);  // INT_MAX
    test_strtol("-2147483648", 10); // INT_MIN
    test_strtol("9999999999999999999999999", 10);  // Overflow
    test_strtol("-9999999999999999999999999", 10); // Underflow
    test_strtol("123", 2);  // Invalid base 2 input

    return 0;
}
