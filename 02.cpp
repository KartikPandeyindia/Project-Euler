//Find the sum of even-valued Fib terms, terms should not exceed 4million

#include <iostream>
#define Approach 1 //Place values for switch approaches

#if Approach == 1 //Standard
int main()
{
    unsigned int x = 1, y = 1, z = 0; 
    unsigned int sum = 0;

    for( x; x <= 4000000; x = y + z)
    {
        z = y;
        y = x;
            if (x % 2 == 0)
            sum += x;
    }
    std::cout << sum << std::endl;
    
    return 0;
}

#elif Approach == 2 //Dynamic Programming 
static unsigned int sum = 0;
class DP
{
    public:
    int fib(unsigned int n)
    {
        unsigned int f[40 + 2];
        int i;

        f[0] = 0; 
        f[1] = 1;

        for(i = 2; i<= 40; i++)
        {
            f[i] = f[i - 1] + f[i - 2];
            if (f[i] % 2 == 0 && f[i]<=n)
            sum += f[i];
        } 
        return 0;
    }
};
int main()
{
    DP foo;
    const unsigned int num = 4000000;
    foo.fib(num);
    std::cout << sum ;
    return 0;
}

#elif Approach == 3 
/* 
--Modular Arithmetic [Special property]--
Fib Sequences occurs as: [O, O, E], [O, O, E], [O, O, E], [O, O, E]
z = 1, y = 1 
-> z, y, [y + z], (z + 2y), (2z + 3y), [3z + 5y], (5z + 8y), (8z + 13y), [13z + 21y]...
-> 1, 1, [2], 3, 5, [8], 13, 21, [34]...
Every third value is Even, hence we do not have to evaluate remainder.
*/ 
int main()
{
    unsigned int x = 2, y = 1, z = 1; 
    unsigned int sum = 0;

    for( x; x <= 4000000;)
    {
        sum += x; 

        for (int i = 0; i < 3; i++)
        {
            z = y;
            y = x;
            x = y + z;
        } 
    }
    std::cout << sum << std::endl;
    
    return 0;
}

#endif

/*
--Other methods--
- golden ration methond
- Second Order linear difference equation
- https://projecteuler.net/thread=2;page=5#236487 this which I couldn't figure out (yet!)
*/