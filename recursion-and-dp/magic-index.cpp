/**
 * Given a sorted array of distinct integers A[0...n-1]
 * A magic index is defined as A[i] = i
 * Find the index i that satisfies this
 */

#include <vector>
#include <iostream>

using namespace std;

int findMagicIndex(vector<int>& v, int start, int end)
{
    if (start > end) return -1;

    int mid = (start + end) / 2;

    if (v[mid] == mid) return mid;

    else if (v[mid] < mid) return findMagicIndex(v, mid+1, end);

    return findMagicIndex(v, start, mid-1);
}

int findMagicIndexDups(vector<int>& v, int start, int end)
{
    if (start > end) return -1;

    int mid = (start + end) / 2;

    if (v[mid] == mid) return mid;

    int left = findMagicIndex(v, start, min(mid, v[mid]));

    if (left != -1) return left;

    return findMagicIndexDups(v, max(mid+1, v[mid]), end);
}

int main()
{
    vector<int> v = {-4, 0, 2, 4, 5, 7, 9, 14};

    cout << endl;

    printf("Finding magic index %d\n", findMagicIndex(v, 0, v.size()-1));

    cout << endl;

    v = {-10, -5, 2, 2, 2, 3, 4, 7, 9, 12, 13};

    printf("Finding magic index with duplicate values in the array %d\n", findMagicIndexDups(v, 0, v.size()-1));
}
