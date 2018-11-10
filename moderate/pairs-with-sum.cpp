/**
 * Given a sum, and an array, compute all pairs that sum to the given target
 */

#include <iostream>
#include <limits>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

template <class T>
class Pair
{
    private:
        /**
         * The tuple (one, two) representing the pair
         * @param T one
         * @param T two
         */
        T one, two;

    public:
        Pair(T u, T v)
        {
            one = u;

            two = v;
        }

        /**
         * Returns the default sum operator of tuple
         * @returns T
         */
        T getSum()
        {
            return this->one + this->two;
        }

        /**
         * Prints the tuple
         * @returns void
         */
        void print()
        {
            printf("(%d, %d)\n", this->one, this->two);
        }
};

unordered_set<int> sum;

vector<Pair<int>> getSumPairs(vector<int>& v, int target)
{
    vector<Pair<int>> res;

    for (int elem : v)
    {
        int complement = target - elem;

        if (sum.find(complement) != sum.end())
        {
            res.push_back(Pair<int>(elem, complement));
        }

        sum.insert(elem);
    }

    return res;
}

vector<Pair<int>> getSumPairsSorting(vector<int>& v, int target)
{
    sort(v.begin(), v.end());

    int first = 0; int last = v.size()-1;

    vector<Pair<int>> res;

    while (first < last)
    {
        int sum = v[first] + v[last];

        if (sum == target)
        {
            res.push_back(Pair<int>(v[first], v[last]));

            first++; last--;
        }
        else if (sum < target)
        {
            first++;
        }
        else
        {
            last--;
        }
    }

    return res;
}

int main()
{
    vector<int> v1 = {1, 3, 15, 11, 2, -10, -6, 4};

    vector<Pair<int>> res = getSumPairs(v1, 5);

    for (Pair<int> p : res)
    {
        p.print();
    }

    cout << endl;

    res = getSumPairsSorting(v1, 5);

    for (Pair<int> p : res)
    {
        p.print();
    }
}
