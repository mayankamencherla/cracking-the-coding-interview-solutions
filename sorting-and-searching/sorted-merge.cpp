#include <vector>
#include <iostream>

using namespace std;

void sortedMerge(vector<int>& v1, vector<int>& v2, int v1Len)
{
    int ind1 = v1Len-1; int ind2 = v2.size()-1;

    for (int i=v1.size()-1; i>=0; i--)
    {
        if (v1[ind1] <= v2[ind2])
        {
            v1[i] = v2[ind2];

            ind2--;
        }
        else
        {
            v1[i] = v1[ind1];

            ind1--;
        }

        if (ind2 < 0) break;
    }
}

int main()
{
    vector<int> v1 = {1, 3, 5, 7, 9, 0, 0, 0, 0};

    vector<int> v2 = {2, 4, 6, 8};

    sortedMerge(v1, v2, 5);

    for (int elem : v1) cout << elem << " ";

    cout << endl;
}
