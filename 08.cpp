//Find 13 adjacent digits that have the greatest product in a given [data] 1000 digit number
//Time : 1h 30m     Answer : 23514624000

#include <iostream>
#include <vector>
#define data unsigned long long
#define state 1

#if state == 1

//Method: (DATA, window_size) ---> largest product of adjacent digits  
data func(char textnum[], int n)
{
    //Sub-method: DATA[char] ---> DATA[int]
    int bignum[1000];

    for(int i = 0; i < 1000; i++ )
    {
        bignum[i] = int( textnum[i] ) - 48;
    }

    //Chunking: In between zeros, all the (adjacent digits) < n are dropped
    //int chunk[] : holds the index to an appropriate "chunk"
    int cnt = 0, s = 0;

    std::vector<int> chunks;

    for ( int i = 0; i < 1000; i++ )
    {
        if( bignum[i] )
            cnt++;
        else cnt = 0;
        if( cnt >= n )
        {
            chunks.push_back((i + 1) - n); 
        }
    }

    //Main Logic: 
    data p = 1, x = 1;
    for ( int i = 0; i < chunks.size(); i++)    //Loop: (processing through chunks in DATA)
    {
        for ( int j = 0; j < n; j++ )           //Loop: (processing till the window_size)
        {
            p *= bignum[chunks.at(i) + j];      //Product of n adjacent digits
        }
        if ( p > x )                            //Largest 
            x = p;
        p = 1;
    }

    return x;
}

int main()
{
    int n = 13;
    char textnum[] = "7316717653133062491922511967442657474235534919493496983520312774506326239578318016984801869478851843858615607891129494954595017379583319528532088055111254069874715852386305071569329096329522744304355766896648950445244523161731856403098711121722383113622298934233803081353362766142828064444866452387493035890729629049156044077239071381051585930796086670172427121883998797908792274921901699720888093776657273330010533678812202354218097512545405947522435258490771167055601360483958644670632441572215539753697817977846174064955149290862569321978468622482839722413756570560574902614079729686524145351004748216637048440319989000889524345065854122758866688116427171479924442928230863465674813919123162824586178664583591245665294765456828489128831426076900422421902267105562632111110937054421750694165896040807198403850962455444362981230987879927244284909188845801561660979191338754992005240636899125607176060588611646710940507754100225698315520005593572972571636269561882670428252483600823257530420752963450";
    std::cout << func(textnum, n);
    return 0;
}

#elif state == 2
//Best optimized version already? - No
/*
* Think about chunks greater thatn window_size
  They have many in-between chunks in them
  
  These in-between chunks are processing repetitive digits.
*/
#endif