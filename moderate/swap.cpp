#include <iostream>

using namespace std;

/**
 * Swaps 2 numbers without temp variable
 *
 * @param int& a
 * @param int& b
 * @returns void
 */
void swap(int& a, int& b)
{
    a -= b;

    b += a;

    a = b - a;
}

int main()
{
    int a = 23; int b = 56;

    printf("Before swapping, a=%d and b=%d\n", a, b);

    swap(a, b);

    printf("After swapping, a=%d and b=%d\n", a, b);
}
