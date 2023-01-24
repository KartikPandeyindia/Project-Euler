//Largest prime factor of a number 600851475143... Ans = 6857

#include <iostream>
#include <cmath>
#define switch 1 

#if switch == 1 //Trial Division

int main()
{
    
    long long x = 0;            //The max prime factor
    long long n = 600851475143; //The number to be factored

    while (n % 2 == 0)  //To check for even and remove all 2 divisible
    {
        n /= 2; 
        x = 2;
    }
    while (n % 3 == 0)  //For 3
    {
        n /= 3;
        x = 3;
    }
    for(int i = 5; i <= sqrt(n); i += 2 ) //only need to go till square root - square reduces as i increases
    {
        while( n % i == 0 )
        {
            n /= i;
            x = i;
        }
    } 

    std::cout << x;
    return 0;
}

#elif switch == 2 //Other faster methods

#endif

