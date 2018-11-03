#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

/**
 * This method returns a url encoded version of input string s
 * The input string contains sufficient space to add encoded elements in place
 *
 * Space complexity : O(1)
 * Time complexity  : O(N) where N is the size of the strings s
 *
 * @param string s
 * @param int len
 * @return string
 */
string urlIfyInPlace(string s, int len)
{
    int index = len-1;

    int i = s.size()-1;

    while (i >= 0)
    {
        if (s[index] != ' ')
        {
            s[i] = s[index];
        }
        else
        {
            s[i]   = '0';
            s[i-1] = '2';
            s[i-2] = '%';

            i -= 2;
        }

        i--;

        index--;
    }

    return s;
}

int main()
{
    string s = "Mr John Smith    ";

    int len = 13;

    string res = urlIfyInPlace(s, len);

    cout << "Result using in place aproach: " << res << endl;
}
