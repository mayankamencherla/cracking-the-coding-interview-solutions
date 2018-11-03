#include <iostream>
#include <unordered_map>

using namespace std;

int countCompression(string s)
{
    int count = 0;

    for (int i=0; i<s.size(); i++)
    {
        if (i == 0 || s[i] != s[i-1]) count++;
    }

    return count + count;
}

/**
 * Compresses string s, and in case the compressed string is
 * not smaller than original string, it returns the original string
 *
 * Time complexity : O(p), where p = s.size()
 *
 * @param string s
 * @return string
 */
string compressString(string s)
{
    // We want to check if the compressed string is shorter than original
    // If not, we return the original string
    if (countCompression(s) >= s.size()) return s;

    string res;

    int count = 0;

    for (int i=0; i<s.size(); i++)
    {
        if (i == 0)
        {
            count = 1;
        }
        else if (i > 0 && s[i] != s[i-1])
        {
            // String concatenation is O(n^2)
            // So instead we use push_back, which is amortized constant
            res.push_back(s[i-1]);

            res.push_back(count + '0');

            count = 1;
        }
        else if (i > 0 && s[i] == s[i-1])
        {
            count++;
        }
    }

    res.push_back(s[s.size()-1]);

    res.push_back(count + '0');

    return res;
}


int main()
{
    // We will use a O(N) algorithm to compress the string
    cout << "Compressing string aabcccccaaa should be a2b1c5a3 and is " << compressString("aabcccccaaa") << endl;
    cout << "Compressing string abcdef should be abcdef and is " << compressString("abcdef") << endl;
    cout << "Compressing string aabcdef should be aadcdef and is " << compressString("aabcdef") << endl;
}
