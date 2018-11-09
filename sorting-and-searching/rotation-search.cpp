/**
 * Write an algorithm to search for an element in a rotated sorted array
 */

#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

int binarySearchHelper(vector<int>& v, int start, int end, int search)
{
    if (start > end) return -1;

    int mid = (start + end) / 2;

    if (v[mid] == search) return mid;

    else if (v[mid] < search) return binarySearchHelper(v, mid+1, end, search);

    return binarySearchHelper(v, start, mid-1, search);
}

int binarySearch(vector<int>& v, int start, int end, int size, int search)
{
    if (size <= 0) return -1;

    int mid = (start + (size/2)) % size;

    if (v[mid] == search) return mid;

    else if (v[mid] < search)
    {
        int newStart = (mid+1) % size;

        if (mid < start) return binarySearchHelper(v, newStart, end, search);

        if (mid < v.size()-1)
        {
            int res = binarySearchHelper(v, newStart, v.size()-1, search);

            if (res != -1) return res;
        }

        return binarySearchHelper(v, 0, end, search);
    }

    if (mid > start) return binarySearchHelper(v, start, mid-1, search);

    int res = binarySearchHelper(v, 0, mid-1, search);

    if (res != -1) return res;

    return binarySearchHelper(v, mid+1, v.size()-1, search);
}

int main()
{
    vector<int> v = {7, 8, 9, 10, 11, 12, 13, 1, 2, 3, 4, 5, 6};

    for (int elem : v)
    {
        int index = binarySearch(v, 7, 6, 10, elem);

        printf("Found the %d element at index %d\n", elem, index);
    }
}
