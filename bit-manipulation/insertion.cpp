#include <iostream>
#include <bitset>

using namespace std;

/**
 * Insert m into n such that m starts at bit i, and ends at j
 * m contains at least j-i+1 bits
 *
 * @param int& n
 * @param int m
 * @param int i
 * @param int j
 * @return void
 */
void insertion(int& n, int m, int i, int j)
{
    // left shift by i
    // The MSB will be at most j
    m <<= i;

    int ones = ~0;

    // clear bits [0, j] in n
    int mask = ones << (j+1);

    // clear bits [i, 32]
    int mask2 = ~(ones << i);

    mask |= mask2;

    n &= mask;

    n |= m;
}

int main()
{
    // 10000000000
    int n = 1 << 11;

    // 10011
    int m = 19;

    int i=4; int j=10;

    bitset<20> nb(n);

    bitset<20> mb(m);

    printf("n before insertion %s\n\n", nb.to_string().c_str());

    printf("m being inserted   %s\n\n", mb.to_string().c_str());

    insertion(n, m, i , j);

    bitset<20> nb2(n);

    printf("n after insertion  %s\n", nb2.to_string().c_str());
}
