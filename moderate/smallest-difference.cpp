/**
 * Given 2 arrays, compute the smallest difference between 2 numbers
 * For eg. {1, 3, 15, 11, 2}, {23, 127, 235, 19, 8}
 * Ans = {11, 8}
 */

#include <iostream>
#include <limits>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> getSmallestDiffPair(vector<int>& v1, vector<int>& v2)
{
    int diff = numeric_limits<int>::max();

    sort(v1.begin(), v1.end());

    sort(v2.begin(), v2.end());

    vector<int> res;

    int ind1 = 0, ind2 = 0;

    while (ind1 < v1.size() && ind2 < v2.size())
    {
        int currDiff = v1[ind1] - v2[ind2];

        if (diff > abs(currDiff))
        {
            diff = abs(currDiff);

            res = {v1[ind1], v2[ind2]};
        }

        if (currDiff < 0) ind1++;

        else ind2++;
    }

    return res;
}

int main()
{
    vector<int> v1 = {1, 3, 15, 11, 2};

    vector<int> v2 = {23, 127, 235, 19, 8};

    vector<int> res = getSmallestDiffPair(v1, v2);

    printf("The elements with the smallest difference are %d and %d\n", res[0], res[1]);
}
