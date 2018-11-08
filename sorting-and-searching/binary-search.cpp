/**
 * Implementation of binary search
 */

#include <vector>
#include <iostream>

using namespace std;

int binarySearchIter(vector<int>& v, int search)
{
    int low = 0; int high = v.size()-1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (v[mid] == search) return mid;

        else if (v[mid] < search) low = mid+1;

        else high = mid-1;
    }

    return -1;
}

int binarySearchRec(vector<int>& v, int search, int start, int end)
{
    if (start > end) return -1;

    int mid = (start + end) / 2;

    if (v[mid] == search) return mid;

    else if (v[mid] < search) return binarySearchRec(v, search, mid+1, end);

    return binarySearchRec(v, search, start, mid-1);
}

int binarySearchRec(vector<int>& v, int search)
{
    return binarySearchRec(v, search, 0, v.size()-1);
}

int main()
{
    vector<int> v = {1, 4, 5, 6, 8, 9, 11, 14, 15, 17, 18};

    for (int elem : v)
    {
        int search = elem;

        int res1 = binarySearchRec(v, search);

        int res2 = binarySearchIter(v, search);

        printf("Recursively searching for %d in the array yields : %d as the index where %d lies \n\n", search, res1, search);

        printf("Iteratively searching for %d in the array yields : %d as the index where %d lies \n\n", search, res2, search);
    }
}
