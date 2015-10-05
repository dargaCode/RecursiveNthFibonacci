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
long long get_nth_fib(int n);

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
    // good input
    int n = atoi(argv[1]);
    long long output = get_nth_fib(n);
    printf("Fibonacci Number #%i = %lli \n", n, output);

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
    int n = atoi(argv[1]);
    // nth fib argument out of range
    if (n < 1 || n > MAX_FIB)
    {
        return false;
    }
    return true;
}

long long get_nth_fib(int n)
{
    return 1;
}
