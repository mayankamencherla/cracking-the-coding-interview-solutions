#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

/**
 * This method checks whether a string is a permutation of a palindrome
 * This algorithm is not case sensitive
 *
 * Space complexity : O(1)
 * Time complexity  : O(N) where N is the size of the strings s
 *
 * @param string s
 * @return bool
 */
bool permutationOfPalindrome(string s)
{
    //
    // A string is a permutation of a palindrome if
    // it contains <= 1 elements that have odd frequency in the string
    //

    int odd = 0;

    unordered_map<char, int> hash;

    for (char c : s)
    {
        hash[tolower(c)]++;

        int count = hash[c];

        if (count % 2 == 1) odd++;

        else odd--;
    }

    return odd <= 1;
}

int main()
{
    string s1 = "Tact coa";
    string s2 = "mayank";
    string s3 = "ManNAm";

    cout << "Checking if Tact coa is a permutation of a palindrome: " << permutationOfPalindrome(s1) << endl;

    cout << "Checking if mayank is a permutation of a palindrome: " << permutationOfPalindrome(s2) << endl;

    cout << "Checking if ManNAm is a permutation of a palindrome: " << permutationOfPalindrome(s3) << endl;
}
