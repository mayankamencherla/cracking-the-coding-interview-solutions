/**
 * Write an algorithm to search for an element in a data structure that returns the element at index i
 */

#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Listy
{
    private:
        vector<int> v;
        int size;
    public:
        Listy(vector<int>& list)
        {
            this->v = list;
            this->size = v.size();
        }

        int getElementAt(int i)
        {
            if (i < 0 || i >= size) return -1;

            return v[i];
        }
};

int binarySearch(Listy& l, int search)
{
    int end = 1;

    int prev = 0;

    while (l.getElementAt(end-1) < search && l.getElementAt(end-1) != -1)
    {
        prev = end-1;

        end *= 2;
    }

    end--;

    int low = prev; int high = end;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        int val = l.getElementAt(mid);

        if (val == search) return mid;

        else if (val == -1 || val > search) high = mid-1;

        else low = mid+1;
    }

    return -1;
}

int main()
{
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 ,16, 17};

    Listy l = Listy(v);

    for (int elem : v)
    {
        printf("Searching for %d, found at %d\n", elem, binarySearch(l, elem));
    }
}
