/**
 * Given a string, compute all permutations of the string
 * The string has only unique characters
 */

#include <vector>
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

vector<string> allPermutations(unordered_map<char, int>& count, string& prefix, int n)
{
    if (n == 0) return {prefix};

    unordered_map<char, int>::iterator it;

    vector<string> res;

    for (it=count.begin(); it!=count.end(); it++)
    {
        if (it->second == 0) continue;

        string newPrefix = prefix + it->first;

        it->second--;

        vector<string> perms = allPermutations(count, newPrefix, n-1);

        it->second++;

        res.insert(res.end(), perms.begin(), perms.end());
    }

    return res;
}

unordered_map<char, int> getFrequencyMap(string perm)
{
    unordered_map<char, int> count;

    for (char c : perm) count[c]++;

    return count;
}

int main()
{
    string perm;

    cout << "Enter a string to permute : " << endl;

    cin >> perm;

    unordered_map<char, int> count = getFrequencyMap(perm);

    string prefix = "";

    vector<string> res = allPermutations(count, prefix, perm.size());

    printf("Printing all permutations, there are %zu in number\n\n", res.size());

    for (string s : res) cout << s << endl;
}
