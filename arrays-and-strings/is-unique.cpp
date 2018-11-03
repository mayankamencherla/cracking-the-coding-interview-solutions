#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

/**
 * This method uses a hash table to keep a check on number of occurences of each character
 *
 * @param input
 * @return bool
 */
bool fast(string input)
{
    unordered_map<char, int> hash;

    for (char c : input)
    {
        c = tolower(c);

        // An iterator to the character's position in the table
        unordered_map<char, int>::iterator it = hash.find(c);

        // We have found an ocurrence of the character, and therefore
        // this string does not have all unique characters
        if (it != hash.end()) return false;

        hash[c]++;
    }

    return true;
}

/**
 * This method uses sorting to solve the problem with constant memory
 *
 * @param input
 * @return bool
 */
bool constantMemory(string input)
{
    sort(input.begin(), input.end());

    for (int i=1; i<input.size(); i++)
    {
        char c1 = tolower(input[i]);

        char c2 = tolower(input[i-1]);

        if (c1 == c2) return false;
    }

    return true;
}

int main()
{
    string input = "mayank";

    bool ret1 = fast(input);

    bool ret2 = constantMemory(input);

    cout << "Result using fast algorithm: " << ret1 << endl;

    cout << "Result using sorting and O(1) memory: " << ret2 << endl;
}
