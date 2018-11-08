/**
 * Given a set of coins, and change,
 * find the number of ways to get change for the coins
 */

#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<string, int> memo;

int numWaysToChangeCoins(int n, vector<int>& coins, int coin)
{
    if (n < 0 || coin >= coins.size()) return 0;

    else if (n == 0) return 1;

    string key = to_string(n) + " " + to_string(coin);

    if (memo.find(key) != memo.end()) return memo[key];

    int ways = 0;

    int denom = 0;

    while (denom*coins[coin] <= n)
    {
        int cost = denom*coins[coin];

        ways += numWaysToChangeCoins(n - cost, coins, coin+1);

        denom++;
    }

    memo[key] = ways;

    return ways;
}

int numWaysToChangeCoinsDP(int n, vector<int>& coins)
{
    int c = coins.size();

    vector<vector<int>> dp(c+1, vector<int>(n+1, 0));

    for (int row=0; row<=c; row++) dp[row][0] = 1;

    for (int i=1; i<=c; i++)
    {
        for (int j=1; j<=n; j++)
        {
            int coin = coins[i-1];

            dp[i][j] = dp[i-1][j];

            if (coin <= j)
            {
                dp[i][j] += dp[i][j-coin];
            }
        }
    }

    return dp[c][n];
}

int main()
{
    int n;

    cout << "Enter a value to exchange : " << endl;

    cin >> n;

    vector<int> coins = {1, 5, 10, 25};

    printf("There are %d ways to get change for %d \n\n", numWaysToChangeCoins(n, coins, 0), n);

    printf("There are %d ways to get change for %d using DP \n\n", numWaysToChangeCoinsDP(n, coins), n);
}
