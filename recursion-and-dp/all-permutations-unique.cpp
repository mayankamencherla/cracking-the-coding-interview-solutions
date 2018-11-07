/**
 * Given a string, compute all permutations of the string
 * The string has only unique characters
 */

#include <vector>
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

vector<string> allPermutations(string val, string prefix)
{
    if (val.size() == 0) return {prefix};

    vector<string> res;

    for (int i=0; i<val.size(); i++)
    {
        string newVal = val;

        newVal.erase(newVal.begin() + i);

        string newPrefix = prefix + val[i];

        vector<string> perms = allPermutations(newVal, newPrefix);

        res.insert(res.end(), perms.begin(), perms.end());
    }

    return res;
}

int main()
{
    string perm;

    cout << "Enter a string to permute : " << endl;

    cin >> perm;

    string prefix = "";

    vector<string> res = allPermutations(perm, prefix);

    printf("Printing all permutations, there are %zu in number\n\n", res.size());

    for (string s : res) cout << s << endl;
}
