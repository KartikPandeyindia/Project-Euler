//Smallest number evenly divisible by [20 to 2] 
//Time: 24m     Ans: 232792560

#include <iostream>
#define switch 2

#if switch == 1     //Brute force

int func()
{
    //Loop: ( i: 21 -> inf) smallest possibility
    for ( unsigned long i = 21; i < 1000000000000000000; i++)      
    {
        int x = 20;
        //Test: num is divible by [20 -> 1]
        while ( i % x == 0 )
        {
            x--;
            if(x == 1)
                return i;
        }
    }
    return 0;
}

int main()
{
    std::cout << func();
    return 0;
}

#elif switch == 2   //LCM method
#define data unsigned long long

//Returns: HCF of (a, b) only if [a > b]
data HCF( data a, data b)
{
    data r, q;
    while(1)    
    {
        q = a / b;
        r = a % b;
        
        if (!r)    // remainder is zero
            return b;  
        
        a = b;
        b = r;
    }
}

data func()
{
    data x = 1;

    for( data i = 10; i >= 2; i-- )
    {
        data hcf = ( x > i ) ? HCF( x, i ) : HCF( i, x );
        data lcm = (x * i) / hcf;           //LCM = Product / HCF
        x = lcm;        
    }
    return x;
}

int main()
{
    std::cout << func();
    return 0;
}
#endif