#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

/**
 * This method checks if s1 is a permutation of s2.
 * This method uses a hash table to compare if both hashes are the same
 * This algorithm is case sensitive
 *
 * Space complexity : O(N), where N is the size of the string s1, s2
 * Time complexity  : O(N) where N is the size of the strings s1, s2
 *
 * @param string s1
 * @param string s2
 * @return bool
 */
bool isPermutationHashTable(string s1, string s2)
{
    if (s1.size() != s2.size()) return false;

    unordered_map<char, int> hash;

    for (char c : s1) hash[c]++;

    for (char c : s2)
    {
        unordered_map<char, int>::iterator it = hash.find(c);

        if (it == hash.end() || it->second == 0) return false;

        // If the character exists in s1, we decrement its frequency
        it->second--;
    }

    return true;
}

/**
 * This method checks if s1 is a permutation of s2.
 * This method uses sorting to
 * This algorithm is case sensitive
 *
 * Space complexity : O(1)
 * Time complexity  : O(NlogN) where N is the size of the strings s1, s2
 *
 * @param string s1
 * @param string s2
 * @return bool
 */
bool isPermutationSorting(string s1, string s2)
{
    if (s1.size() != s2.size()) return false;

    sort(s1.begin(), s1.end());

    sort(s2.begin(), s2.end());

    return s1 == s2;
}

int main()
{
    string s1, s2;

    cin >> s1;
    cin >> s2;

    bool hashTable = isPermutationHashTable(s1, s2);

    bool sorting = isPermutationSorting(s1, s2);

    cout << "Result using hash table approach: " << hashTable << endl;

    cout << "Result using sorting approach: " << sorting << endl;
}
