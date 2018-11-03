#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

/**
 * This method checks whether string s1 is 1 edit away from string s2
 * An edit can be { insert / delete / replace }
 *
 * Space complexity : O(NM) where N, M are the sizes of strings s1, s2
 * Time complexity  : O(NM) where N, M are the sizes of strings s1, s2
 *
 * @param string s1
 * @param string s2
 * @return bool
 */
bool oneEditAwayDP(string s1, string s2)
{
    int diff = abs((int)(s1.size() - s2.size()));

    // If 2 strings sizes differ by or over 2, then they cannot be 1 edit away
    if (diff >= 2) return false;

    int n = s1.size(); int m = s2.size();

    // edits(i+1, j+1) indicates the number of edits needed to convert
    // s1(0...i) into s2(0...j)
    vector<vector<int>> edits(n+1, vector<int>(m+1, 0));

    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
        {
            if (s1[i] == s2[j])
            {
                // If equal, then the edits(i+1, j+1) is the same as edits(i, j)
                edits[i+1][j+1] = edits[i][j];
            }
            else
            {
                //
                // In this case we have 3 options that require 1 edit
                // a. edits(i, j) + replace s1[i] with s2[j]
                // b. edits(i, j-1) + delete s1[i]
                // c. edits(i-1, j) + insert s2[j]
                //
                edits[i+1][j+1] = min(edits[i][j] + 1, min(edits[i][j+1] + 1, edits[i+1][j] + 1));
            }
        }
    }

    return edits[n][m] <= 1;
}

/**
 * This method checks if s1 can be transformed into s2 using 1 replace
 *
 * @param string s1
 * @param string s2
 * @return bool
 */
bool oneReplaceAway(string s1, string s2)
{
    bool replace = false;

    int n = s1.size();

    for (int i=0; i<s1.size(); i++)
    {
        if (s1[i] != s2[i])
        {
            if (!replace) replace = true;

            else return false;
        }
    }

    return true;
}

/**
 * This method checks if s1 can be transformed into s2 using 1 insert
 *
 * @param string s1
 * @param string s2
 * @return bool
 */
bool oneInsertAway(string s1, string s2)
{
    // s1 is the shorter string
    int n = s1.size();

    int i=0, j=0;

    bool insert = false;

    while (i < n)
    {
        if (s1[i] == s2[j])
        {
            i++;
        }
        else if (!insert)
        {
            insert = true;
        }
        else return false;

        j++;
    }

    return true;
}

/**
 * This method checks is s1 can be transformed into s2 using at most 1 edit
 *
 * @param string s1
 * @param string s2
 * @return bool
 */
bool oneEditAwayLinear(string s1, string s2)
{
    int diff = s1.size() - s2.size();

    // If 2 strings sizes differ by or over 2, then they cannot be 1 edit away
    if (abs(diff) >= 2) return false;

    else if (diff == 0) return oneReplaceAway(s1, s2);

    // Check if s2 can be transformed into s1 using 1 insert
    else if (diff == 1) return oneInsertAway(s2, s1);

    // Check if s1 can be transformed into s2 using 1 insert
    return oneInsertAway(s1, s2);
}

int main()
{
    // We will use a O(NM) algorithm to determine whether 2 strings are 1 edit away
    cout << "Checking is mayank is one edit away from makank: " << oneEditAwayDP("mayank", "makank") << endl;
    cout << "Checking is mayank is one edit away from makany: " << oneEditAwayDP("mayank", "makany") << endl;
    cout << "Checking is mayank is one edit away from mayan : " << oneEditAwayDP("mayank", "mayan") << endl;
    cout << "Checking is maynk is one edit away from mayank : " << oneEditAwayDP("maynk", "mayank") << endl;

    cout << endl;

    // We can use a O(N) algorithm to determine whether 2 strings are 1 edit away
    cout << "Checking is mayank is one edit away from makank in O(n): " << oneEditAwayLinear("mayank", "makank") << endl;
    cout << "Checking is mayank is one edit away from makany in O(n): " << oneEditAwayLinear("mayank", "makany") << endl;
    cout << "Checking is mayank is one edit away from mayan in O(n) : " << oneEditAwayLinear("mayank", "mayan") << endl;
    cout << "Checking is maynk is one edit away from mayank in O(n) : " << oneEditAwayLinear("maynk", "mayank") << endl;
}
