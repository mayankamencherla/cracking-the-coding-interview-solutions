/**
 * Write an algorithm to search for an element in a data structure that returns the element at index i
 */

#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

int binarySearch(vector<string>& v, string search, int start, int end)
{
    if (start > end) return -1;

    int mid = (start + end) / 2;

    int mid1 = mid; int mid2 = mid;

    while (mid1 >= start && v[mid1].size() == 0) mid1--;

    while (mid2 <= end && v[mid2].size() == 0) mid2++;

    if (mid1 < start && mid2 > end) return -1;

    else if (v[mid1] == search) return mid1;

    else if (v[mid2] == search) return mid2;

    else if (v[mid2] < search) return binarySearch(v, search, mid2+1, end);

    return binarySearch(v, search, start, mid1-1);
}

int main()
{
    vector<string> v = {"abc", "", "", "", "ball", "", "", "", "", "cat", "", "", "dog", ""};

    for (string elem : v)
    {
        if (elem.size() == 0) continue;

        printf("Searching for %s, found at %d\n", elem.c_str(), binarySearch(v, elem, 0, v.size()-1));
    }
}
