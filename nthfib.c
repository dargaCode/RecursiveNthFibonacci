#include <stdio.h>
#include <cs50.h>

// printf ANSI colors
#define COLOR_RED     "\x1b[31m"
#define COLOR_GREEN   "\x1b[32m"
#define COLOR_YELLOW  "\x1b[33m"
#define COLOR_BLUE    "\x1b[34m"
#define COLOR_MAGENTA "\x1b[35m"
#define COLOR_CYAN    "\x1b[36m"
#define COLOR_RESET   "\x1b[0m"

// constants
#define MAX_FIB 75

// prototypes
bool is_input_valid(int argc, string argv[]);

int main(int argc, string argv[])
{
    // bad input
    if (!is_input_valid(argc, argv))
    {
        printf(COLOR_RED);
        printf("Usage: nthfib <Fibonacci number (1 - %i)>\n",
            MAX_FIB);
        printf(COLOR_RESET);
        // failure
        return 1;
    }

    // success
    return 0;
}

bool is_input_valid(int argc, string argv[])
{
    // wrong number of arguments
    if (argc != 2)
    {
        return false;
    }
    int nth_fib = atoi(argv[1]);
    // fib number argument out of range
    if (nth_fib < 1 || nth_fib > MAX_FIB)
    {
        return false;
    }
    return true;
}
