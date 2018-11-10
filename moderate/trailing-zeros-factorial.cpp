/**
 * Compute number of trailing zeroes in a factorial(n)
 */

#include <iostream>
#include <limits>

using namespace std;

int trailingZeroes(int n)
{
    int num = 0;

    while (n > 0)
    {
        num += n/5;

        n /= 5;
    }

    return num;
}

int main()
{
    int n;

    cin >> n;

    printf("Number of trailing zeroes in a %d factorial is %d\n", n, trailingZeroes(n));
}
