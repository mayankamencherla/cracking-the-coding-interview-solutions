/**
 * Given 2 numbers, recursively multiply them
 * Without using *, use +, -, >>, <<
 * Minimize the operations listed above
 */

#include <vector>
#include <iostream>
#include <cmath>
#include <unordered_map>

using namespace std;

/**
 * Using a O(b) solution
 */
int multiplyRecursivelyAdd(int a, int b)
{
    if (b == 0) return 0;

    else if (b == 1) return a;

    return a + multiplyRecursivelyAdd(a, b-1);
}

unordered_map<string, int> hashmap;

/**
 * O(log(b))
 */
int multiplyRecursivelyFast(int a, int b)
{
    if (a < b) return multiplyRecursivelyFast(b, a);

    else if (b == 0) return 0;

    else if (b == 1) return a;

    string key = to_string(a) + to_string(b);

    if (hashmap.find(key) != hashmap.end()) return hashmap[key];

    // Reduce the size of the larger problem
    int side = b / 2;

    int area = 2 * multiplyRecursivelyFast(a, side);

    if (b % 2 == 1) area += a;

    hashmap[key] = area;

    return area;
}

int main()
{
    int a = 234; int b = 147;

    printf("Result of multiplying %d and %d is : %d and it should be : %d\n", a, b, multiplyRecursivelyAdd(a, b), a*b);

    printf("Result of multiplying %d and %d is : %d using the fast technique\n", a, b, multiplyRecursivelyFast(a, b));
}
