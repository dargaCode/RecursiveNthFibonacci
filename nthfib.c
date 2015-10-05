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
    long long memorized[n];
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
    return memorized_count >= n;
}

long long get_nth_memorized(long long memorized[], int n)
{
    return memorized[n];
}

long long get_nth_fib(int n, long long memorized[])
{
    recursion_count++;

    // base case for 0 and 1
    // TODO nth fibonacci is actually n+1 being output
    // need to correct off by one and count from 1, not 0
    if (n == 0 || n == 1)
    {
        printf("Fib #%i: %lld \n", n, (long long)n);
        printf("Recursive calls: %i\n", recursion_count);

        memorize_nth(memorized, n, n);
        return n;
    }
    // keep recursing
    else
    {
        // value is already memorized
        if (is_nth_memorized(n))
        {
            long long result = get_nth_memorized(memorized, n);
            printf("Fib #%i: %lld \n", n, result);
            printf("Recursive calls: %i\n", recursion_count);
            return result;

        }
        // value still needs to be memorized
        else
        {
            // go deeper
            long long prev_a = get_nth_fib(n - 1, memorized);
            long long prev_b = get_nth_fib(n - 2, memorized);
            long long result = prev_a + prev_b;
            printf("Fib #%i: %lld \n", n, result);
            printf("Recursive calls: %i\n", recursion_count);

            // memorize result
            memorize_nth(memorized, n, result);

            return result;
        }
    }
}

