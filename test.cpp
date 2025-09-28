#include <iostream>
#include <cmath>

bool isPrime(int a);

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

int main()
{
    int score = 0;

    const int values = 10000002;
    for(int i = 2; i < values; i++)
    {
        auto baselineSolution = isPrimeSolution(i);
        score += test(i, baselineSolution);
    }

    std::cout << "Final score: " << score << "/" << POINTS * (values - 2) << std::endl;

    return 0;
}