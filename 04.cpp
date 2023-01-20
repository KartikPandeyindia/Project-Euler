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

    for ( int n = 999*999; n >= 100*100; n--)  //Going from largest to smallest possibilities
    {
        for ( int k = 999; k > 100; k--)    //Checking for for product of two 3-digit numbers
        {

            if ( n % k == 0 )
            {
                int x = n / k;

                if ( x > 99 && x < 1000 )     //check passed
                {
                    int ans = n; 
                    cnt = 0;   
                    
                    for ( j = -1; ans; )   //Checking for palindrome
                    {
                        j++;
                        arr[ j ] = ans % 10;
                        ans /= 10;
                    }

                    for ( i = 0; i <= (j / 2) && arr[ i ] == arr[ j - i ]; i++ )
                    {
                        cnt++;
                        if ( cnt == (j / 2) + 1 ) //check passed
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

#endif