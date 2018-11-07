#include <unordered_map>
#include <iostream>
#include <vector>

using namespace std;

/**
 * The number of ways to run up n stairs with 1, 2, 3 steps
 */

int numWaysTopDown(int n, unordered_map<int, int>& hash)
{
    if (n <= 2) return n;

    else if (hash.find(n) != hash.end()) return hash[n];

    int ways = numWaysTopDown(n-1, hash) + numWaysTopDown(n-2, hash) + numWaysTopDown(n-3, hash);

    hash[n] = ways;

    return ways;
}

int numWaysDP(int n)
{
    vector<int> memo(n+1, 0);

    memo[1] = 1; memo[2] = 2;

    for (int i=3; i<=n; i++)
    {
        memo[i] = memo[i-1] + memo[i-2] + memo[i-3];
    }

    return memo[n];
}

int main()
{
    int n;

    printf("Enter any number : ");

    cin >> n;

    unordered_map<int, int> hash;

    printf("Nums ways for n=%d using top down with memoization is %d\n", n, numWaysTopDown(n, hash));

    printf("Nums ways for n=%d using bottom up DP is %d\n", n, numWaysDP(n));
}
