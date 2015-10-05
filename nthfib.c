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
int memoized_count = 0;

// prototypes
bool is_input_valid(int argc, string argv[]);
long long get_nth_fib(int n, long long memoized[]);
void memoize_nth(long long memoized[], int n, long long fib);
bool is_nth_memoized(int n);
long long get_nth_memoized(long long memoized[], int n);

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
    long long memoized[n + 1];
    long long output = get_nth_fib(n, memoized);
    printf("\nFinal result: Fibonacci Number #%i = %lli \n\n",
        n, output);

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

void memoize_nth(long long memoized[], int n, long long fib)
{
    memoized[n] = fib;
    memoized_count++;
    printf(COLOR_YELLOW);
    printf("Memoizing Fib #%i = %lld\n", n, fib);
    printf(COLOR_RESET);
}

bool is_nth_memoized(int n)
{
    // adding one since counting from 1, not 0
    bool result = memoized_count >= n + 1;
    if (result)
    {
        printf(COLOR_GREEN);
        printf("Fib #%i already memoized!\n", n);
    }
    else
    {
        printf(COLOR_RED);
        printf("Fib #%i not memoized.\n", n);
    }
    printf(COLOR_RESET);
    return result;
}

long long get_nth_memoized(long long memoized[], int n)
{
    return memoized[n];
}

long long get_nth_fib(int n, long long memoized[])
{
    long long result;
    recursion_count++;
    printf(COLOR_CYAN);
    printf("\n(Recursive calls: %i)\n", recursion_count);
    printf(COLOR_RESET);
    // already memoized
    if (is_nth_memoized(n))
    {
        result = get_nth_memoized(memoized, n);
        printf("Retrieved Fib #%i: %lld\n", n, result);
    }
    // needs to be memoized
    else
    {
        if (n == 1 || n == 2)
        {
            result = n - 1;
            printf(COLOR_GREEN);
            printf("Reached base case! Fib #%i: %lld\n",
                n, result);
            printf(COLOR_RESET);
        }
        // keep recursing
        else
        {
            printf("Recurse Fib #[%i-2]...\n", n);
            long long prev_a = get_nth_fib(n - 2, memoized);
            printf("\nRecurse Fib #[%i-1]...\n", n);
            long long prev_b = get_nth_fib(n - 1, memoized);
            result = prev_a + prev_b;
            printf("\nCalculate Fib #%i: %lld + %lld = %lld\n",
                n, prev_a, prev_b, result);
        }
        // memoize result
        memoize_nth(memoized, n, result);

    }
    return result;
}
