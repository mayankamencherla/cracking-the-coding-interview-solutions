/**
 * Some common sorting algorithms
 */

#include <vector>
#include <iostream>

using namespace std;

vector<int> selectionSort(vector<int> v, int index)
{
    if (index >= v.size()) return v;

    int minIndex = index;

    int minValue = v[minIndex];

    for (int i=index; i<v.size(); i++)
    {
        if (v[i] < minValue)
        {
            minValue = v[i];

            minIndex = i;
        }
    }

    swap(v[index], v[minIndex]);

    return selectionSort(v, index+1);
}

int computePivot(vector<int>& v, int start, int end)
{
    // Random index between [start, end] chosen as pivot
    int random = start + rand() % (end - start + 1);

    swap(v[start], v[random]);

    int l = start+1;

    int value = v[start];

    for (int i=start+1; i<=end; i++)
    {
        if (v[i] <= value)
        {
            swap(v[i], v[l]);

            l++;
        }
    }

    swap(v[start], v[l-1]);

    return l-1;
}

void quickSort(vector<int>& v, int start, int end)
{
    if (start > end) return;

    int pivot = computePivot(v, start, end);

    quickSort(v, start, pivot-1);

    quickSort(v, pivot+1, end);
}

vector<int> quickSort(vector<int>& v)
{
    vector<int> res = v;

    quickSort(res, 0, v.size()-1);

    return res;
}

void merge(vector<int>& v, int start, int mid, int end)
{
    // Merge v[start ... mid] and v[mid+1 ... end]
    int numElems = (end - start + 1);

    vector<int> res(numElems, 0);

    int ind1 = start; int ind2 = mid+1;

    for (int i=0; i<numElems; i++)
    {
        if (ind2 > end || (ind2 <= end && ind1 <= mid && v[ind1] <= v[ind2]))
        {
            res[i] = v[ind1];

            ind1++;
        }
        else
        {
            res[i] = v[ind2];

            ind2++;
        }
    }

    for (int i=start; i<=end; i++) v[i] = res[i-start];
}

void mergeSort(vector<int>& v, int start, int end)
{
    if (start >= end) return;

    int mid = (start + end) / 2;

    mergeSort(v, start, mid);

    mergeSort(v, mid+1, end);

    merge(v, start, mid, end);
}

vector<int> mergeSort(vector<int>& v)
{
    vector<int> res = v;

    mergeSort(res, 0, v.size()-1);

    return res;
}

void printArray(vector<int>& v, string message)
{
    printf("%s\n", message.c_str());

    for (int elem : v) cout << elem << " ";

    cout << endl;
}

int main()
{
    vector<int> v = {10, 7, 4, 5, 1, 2, 8, 9, 3, 6};

    printArray(v, "Pre selection sort");

    vector<int> v1 = selectionSort(v, 0);

    printArray(v1, "Using selection sort");

    cout << endl;

    printArray(v, "Pre quick sort");

    v1 = quickSort(v);

    printArray(v1, "quick sort");

    cout << endl;

    printArray(v, "Pre merge sort");

    v1 = mergeSort(v);

    printArray(v1, "merge sort");
}