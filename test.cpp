#include <iostream>
#include <cmath>

bool isPrime(int a);
int fibonacci(int n);

#define POINTS 1
#define NO_TESTS 5

int test(int value, bool expected)
{
    if(isPrime(value) == expected)
    {
        //std::cout << "Test succeded ... " << POINTS << "p" << std::endl;
        return POINTS;
    }
    
    //std::cout << "Test succeded ... 0p" << std::endl;
    return 0;
}

int testFib(int value, int expected)
{
    if(fibonacci(value) == expected)
    {
        return POINTS;
    }
    return 0;
}


bool isPrimeSolution(int a)
{
    if(a < 1) return false;
    
    int max = 1 + (int) sqrt(a);
    for(int i = 2; i < max; i++)
    {
        if(a % i == 0)
        {
            return false;
        }
    }

    return true;
}

int fibonacciSolution(int n) {
    if (n <= 1) {
        return n;
    }
    int a = 0, b = 1;
    for (int i = 2; i <= n; ++i) {
        int temp = a + b;
        a = b;
        b = temp;
    }
    return b;
}

int main()
{
    int score = 0;
    int total_points = 0;

    const int prime_values = 100;
    for(int i = 2; i < prime_values; i++)
    {
        auto baselineSolution = isPrimeSolution(i);
        score += test(i, baselineSolution);
    }
    total_points += POINTS * (prime_values - 2);

    const int fib_values = 20;
    for(int i = 0; i < fib_values; i++)
    {
        auto baselineSolution = fibonacciSolution(i);
        score += testFib(i, baselineSolution);
    }
    total_points += POINTS * fib_values;

    std::cout << "Final score: " << score << "/" << total_points << std::endl;

    return 0;
}