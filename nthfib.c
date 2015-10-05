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

// global variables
int recursion_count = 0;
int memorized_count = 0;

// prototypes
bool is_input_valid(int argc, string argv[]);
long long get_nth_fib(int n, long long memorized[]);
void memorize_nth(long long memorized[], int n, long long fib);
bool is_nth_memorized(int n);
long long get_nth_memorized(long long memorized[], int n);

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
    // add one extra index to more easily count from 1
    long long memorized[n + 1];
    long long output = get_nth_fib(n, memorized);
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

void memorize_nth(long long memorized[], int n, long long fib)
{
    memorized[n] = fib;
    memorized_count++;
}

bool is_nth_memorized(int n)
{
    // adding one since counting from 1, not 0
    bool result = memorized_count >= n + 1;
    if (result)
    {
        printf(COLOR_GREEN);
        printf("Fib #%i already memorized!\n", n);
    }
    else
    {
        printf(COLOR_RED);
        printf("Fib #%i not memorized.\n", n);
    }
    printf(COLOR_RESET);
    return result;
}

long long get_nth_memorized(long long memorized[], int n)
{
    return memorized[n];
}

long long get_nth_fib(int n, long long memorized[])
{
    long long result;
    recursion_count++;
    printf("Recursive calls: %i\n", recursion_count);

    // already memorized
    if (is_nth_memorized(n))
    {
        result = get_nth_memorized(memorized, n);
    }
    // needs to be memorized
    else
    {
        if (n == 1 || n == 2)
        {
            result = n - 1;
        }
        // keep recursing
        else
        {
            long long prev_a = get_nth_fib(n - 1, memorized);
            long long prev_b = get_nth_fib(n - 2, memorized);
            result = prev_a + prev_b;
        }
        // memorize result
        memorize_nth(memorized, n, result);
    }
    printf("Fib #%i: %lld \n", n, result);
    return result;
}
