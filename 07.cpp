//Find the 10001st prime number
//Time: 1h 30m        Answer:104743

#include <iostream>
#define data unsigned long long
#define gear 1

#if gear == 1       //Brute force - Trial division

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

//Return: whether a number is prime or not
bool isprime (data i)
{
    for ( data j = 2; j < i; j++ )
    {
        if( i % j == 0 )
            return false;
    }
    return true;
}

//Method: Iterates through all the numbers 
//Counts all primes encountered
//Returns the prime at at kth count
data func(int k)
{
    data i;
    int cnt = 0;

    for( i = 2; 1; i++ )
    {
        if( isprime_optimized( i ) )
            cnt++;
        if( cnt >= k )
            return i;
        
    }
}

int main()
{
    std::cout << func(10001);
    return 0;
}

#elif gear == 2         //Faster method
// There is no Absolute method to arrive at the prime at nth index
// Hence,  Approximation method will be used.

#endif
//The best method to conjure primes is to store them in a database as per index.