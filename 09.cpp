//Find the pythagorean triplet whose sum is 1000.
//Time : 10m        Answer: 31875000
#include <iostream>
#define state 1

#if state == 1          //Naive

int main()
{
    for ( int a  = 1; a < 1000; a++ )
        for ( int b = a + 1; b < 1000; b++ )
            for ( int c = b + 1; c < 1000; c++ )
                if ( a + b + c == 1000 )
                    if ( c*c == a*a + b*b )
                        std::cout << a*b*c;
    return 0;
}

#elif state == 2        //Optimized
#define data unsigned long long
data func (int n)
{
    return 0;
}
int main()
{
    int n = 1000;
    std::cout << func(n);
    return 0;
}

#endif