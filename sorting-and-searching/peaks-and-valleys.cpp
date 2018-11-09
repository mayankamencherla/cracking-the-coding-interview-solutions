/**
 * A peak is an element which is >= its adjacent elements
 * A valley is an element which is <= its adjacent elements
 * Given an array, sort it into an alternating sequence of peaks and valley
 * Eg. Input:  {5, 3, 1, 2, 3}
 * Eq. Output: {5, 1, 3, 2, 3}
 */

#include <vector>
#include <iostream>
#include <algorithm>
#include <cstdlib>

using namespace std;

/**
 * O(nlogn) algorithm to convert to peaks and valleys
 * @param vector<int>& v
 * @returns vector<int>
 */
vector<int> convertToPeaksValleys(vector<int>& v)
{
    sort(v.begin(), v.end());

    vector<int> res;

    int valley = 0; int peak = v.size()-1;

    int round = 0;

    while (valley <= peak)
    {
        if (round % 2 == 0)
        {
            res.push_back(v[peak]);

            peak--;
        }
        else
        {
            res.push_back(v[valley]);

            valley++;
        }

        round++;
    }

    return res;
}

/**
 * This is a O(n) algorithm to convert given array into peak and valley
 * @param vector<int>& v
 * @returns void
 */
void convertToPeaksValleysFast(vector<int>& v)
{
    for (int i=1; i<v.size(); i+=2)
    {
        int largerIndex = v[i-1] > v[i+1] ? i-1 : i+1;

        if (v[i] < v[largerIndex]) swap(v[i], v[largerIndex]);
    }
}

int main()
{
    vector<int> v = {5, 3, 1, 2, 3};

    cout << "Array before peak and valley" << endl;

    for (int elem : v) cout << elem << " ";

    cout << endl;

    vector<int> v1 = convertToPeaksValleys(v);

    cout << "Array after peak and valley" << endl;

    for (int elem : v1) cout << elem << " ";

    cout << endl;

    convertToPeaksValleysFast(v);

    cout << "Array after peak and valley using faster algorithm" << endl;

    for (int elem : v) cout << elem << " ";

    cout << endl;
}