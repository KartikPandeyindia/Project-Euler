//Find the difference of "sum of squares" and "square of sums" of first 100 natural numbers
//Time: 20m   Answer: 25164150 

#include <iostream>
#define data unsigned long long

data func(int k)
{
    return ( k * (k + 1) * (k - 1) * (3 * k + 2) ) / 12;
}

int main ()
{
    std::cout << func(100);
    return 0;
}

/*
* Square of Sums (SqS) = ( Ei )^2  //where E is summation notation  
  Sum of Squares (SSq) = E(i)^2
  Diff = SqS - SSq
  --Mathematically--
  SqS = [ k(k+1)/2 ]^2
  SSq = [ k(k+1)(2k+1) ]/6
  for first k natural numbers
*/