#include <cmath>

bool isPrime(int a)
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