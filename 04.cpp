//Find Largest Palindrome which is the product of two 3-digit numbers
// Time : 3h 53m
#include<iostream>

#define switch 1

#if switch == 1 

int func()
{
    int arr[ 6 ];
    int i, j;
    int cnt = 0;

    //Loop: Largest to Smallest
    for ( int n = 999*999; n >= 100*100; n--)  
    {
        //Test: Product of two 3-digit numbers
        for ( int k = 999; k > 100; k--)    
        {

            if ( n % k == 0 )
            {
                int x = n / k;

                if ( x > 99 && x < 1000 )     
                {
                    //Pass
                    int ans = n; 
                    cnt = 0;   
                    //Transfrom: Number to Int Array
                    for ( j = -1; ans; )   
                    {
                        j++;
                        arr[ j ] = ans % 10;
                        ans /= 10;
                    }
                    //Test: Palindrome
                    for ( i = 0; i <= (j / 2) && arr[ i ] == arr[ j - i ]; i++ )
                    {
                        cnt++;
                        if ( cnt == (j / 2) + 1 ) //This works when j is odd. for even j, remove +1
                            //Pass
                            return n;
                    }
                }
            }
        }
    }

    return 0;
}

int main()
{
    std::cout << func();
    return 0;
}
#elif switch == 2
/*
--Optimization--
* Reverse of a palidrome is equal to the palindrome
* n = xyzzyx = 10^5 x + 10^4 y + 10^3 z + 10^2 z + 10 y + x
  => n = 11 ( 9091x + 910y + 100z )
  n = a*b one of the factor is multiple of 11
*/
#endif