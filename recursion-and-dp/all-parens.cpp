/**
 * Given a string, compute all permutations of the string
 * The string has only unique characters
 */

#include <vector>
#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

string insertParen(string item, int i)
{
    string left = item.substr(0, i+1);

    string right = item.substr(i+1);

    return left + "()" + right;
}

unordered_set<string> allPermutationsNaive(int n)
{
    if (n == 0) return {""};

    else if (n == 1) return {"()"};

    unordered_set<string> res = allPermutationsNaive(n-1);

    unordered_set<string> toReturn;

    int balance = 0;

    for (unordered_set<string>::iterator it=res.begin(); it!=res.end(); it++)
    {
        string item = *it;

        for (int i=0; i<item.size(); i++)
        {
            if (item[i] == '(')
            {
                string element = insertParen(item, i);

                toReturn.insert(element);
            }
        }

        toReturn.insert("()" + item);
    }

    return toReturn;
}

void allPermutations(int left, int right, string prefix, vector<string>& res)
{
    if (left == 0 && right == 0) res.push_back(prefix);

    if (left > 0)
    {
        allPermutations(left-1, right, prefix + '(', res);
    }

    if (right > left)
    {
        allPermutations(left, right-1, prefix + ')', res);
    }
}

int main()
{
    int n;

    cout << "Enter a number of parens : " << endl;

    cin >> n;

    unordered_set<string> res = allPermutationsNaive(n);

    printf("Printing all possible parens using naive, there are %zu in number\n\n", res.size());

    for (unordered_set<string>::iterator it=res.begin(); it!=res.end(); it++)
    {
        cout << *it << endl;
    }

    cout << endl;

    string prefix = "";

    vector<string> res1;

    allPermutations(n, n, prefix, res1);

    printf("Printing all possible parens, there are %zu in number\n\n", res1.size());

    for (string s : res1) cout << s << endl;

    cout << endl;
}
