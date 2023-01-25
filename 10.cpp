//Find the sum of primes till n = 2000000
//Time: 7m  Ans: 142913828922

#include <iostream>
#define data unsigned long long


bool isprime_optimized(data i)
{
    if ( i == 2 || i == 3 || i == 5 )
        return true;
    if ( i % 2 == 0 )
        return false;
    if ( i % 3 == 0 )
        return false;
    if ( i % 5 == 0 )
        return false;
    
    for( int j = 7; j <= i / j; j = j + 2 )
    {
        if ( i % j == 0 )
            return false;
        j = j + 4;
        if (i % j == 0 )
            return false;
    }
    return true; 
}

int main()
{
    data n = 10;
    data s = 0;
    for( data i = 2; i < n; i++ )
    {
        if ( isprime_optimized(i) )
            s += i;
    }

    std::cout << s;

    return 0;
}