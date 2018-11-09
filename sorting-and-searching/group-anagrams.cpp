/**
 * Write an algorithm to sort strings so that all anagrams are next to one another
 */

#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

/**
 * O(n) algorithm to compute hash key
 */
string computeKey(string s)
{
    vector<int> key(26, 0);

    for (char c : s) key[c - 'a']++;

    string res;

    for (int i=0; i<26; i++)
    {
        res += ('a' + i) + (key[i] + '0');
    }

    return res;
}

/**
 * O(|v||s|) algorithm to compute hash key
 */
vector<string> sortAnagrams(vector<string>& v)
{
    unordered_map<string, vector<string>> hashmap;

    for (string s : v)
    {
        string key = computeKey(s);

        hashmap[key].push_back(s);
    }

    vector<string> res;

    for (unordered_map<string, vector<string>>::iterator it = hashmap.begin(); it != hashmap.end(); it++)
    {
        for (string s : it->second)
        {
            res.push_back(s);
        }
    }

    return res;
}

int main()
{
    vector<string> v = {"mayank", "amencherla", "yankma", "sort", "laptop", "tsor", "toplap"};

    v = sortAnagrams(v);

    for (string s : v) cout << s << " ";

    cout << endl;
}
