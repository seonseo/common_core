#include <ctype.h>
#include <errno.h>
#include <limits.h>
#include <stdlib.h>

// Function to skip leading whitespace
const char* skip_whitespace(const char* str) {
    while (isspace((unsigned char)*str)) str++;
    return str;
}

// Function to handle the sign of the number
const char* handle_sign(const char* str, int* sign)
{
    if (*str == '-' || *str == '+')
	{
        *sign = (*str == '-') ? -1 : 1;
        str++;
    }
    return str;
}

// Function to determine the base and skip prefix if necessary
const char* determine_base(const char* str, int* base)
{
    if (*base == 0)
	{
        if (*str == '0')
		{
            str++;
            if (*str == 'x' || *str == 'X')
			{
                *base = 16;
                str++;
            }
			else
			{
                *base = 8;
            }
        }
		else
		{
            *base = 10;
        }
    }
	else if (*base == 16)
	{
        if (str[0] == '0' && (str[1] == 'x' || str[1] == 'X'))
		{
            str += 2;
        }
    }
    return str;
}

// Function to convert string segment to number based on base
long convert_to_number(const char* str, int base, int sign, char** endptr)
{
    long result = 0;
    long max_div_base = LONG_MAX / base;
    long max_mod_base = LONG_MAX % base;

    while (*str)
	{
        int digit = isdigit((unsigned char)*str) ? *str - '0' : 
                    isalpha((unsigned char)*str) ? toupper((unsigned char)*str) - 'A' + 10 : -1;
        if (digit < 0 || digit >= base)
            break;
        // Check for overflow
        if (result > max_div_base || (result == max_div_base && digit > max_mod_base))
		{
            errno = ERANGE;
            result = (sign == 1) ? LONG_MAX : LONG_MIN;
            break;
        }
        result = result * base + digit;
        str++;
    }

    if (endptr)
        *endptr = (char *)str;

    return result * sign;
}

// Main strtol function using the helper functions
long strtol(const char *str, char **endptr, int base) {
    int sign = 1;
    str = skip_whitespace(str);
    str = handle_sign(str, &sign);
    str = determine_base(str, &base);
    return convert_to_number(str, base, sign, endptr);
}
