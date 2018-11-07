/**
 * Given a sorted array of distinct integers A[0...n-1]
 * A magic index is defined as A[i] = i
 * Find the index i that satisfies this
 */

#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

vector<int> computeSet(vector<int>& v, int val)
{
    int n = v.size();

    vector<int> res;

    for (int i=0; i<n; i++)
    {
        int mask = (1 << i) & val;

        if (mask) res.push_back(v[i]);
    }

    return res;
}

vector<vector<int>> computePowerSet(vector<int>& v)
{
    int n = v.size();

    int maxVal = pow(2, n) - 1;

    vector<vector<int>> res;

    for (int i=0; i<=maxVal; i++)
    {
        res.push_back(computeSet(v, i));
    }

    return res;
}

int main()
{
    vector<int> v = {1, 2, 3, 4};

    vector<vector<int>> power = computePowerSet(v);

    for (vector<int> v : power)
    {
        if (v.size() == 0) cout << "Empty set";

        for (int elem : v)
        {
            cout << elem << " ";
        }

        cout << endl;
    }
}
