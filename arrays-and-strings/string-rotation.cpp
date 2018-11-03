#include <iostream>
#include <vector>

using namespace std;

/**
 * This method checks if s1 is a rotation of s2 with only 1 call to string's find operation
 *
 * @param string s1
 * @param string s2
 * @return bool
 */
bool isRotation(string s1, string s2)
{
    if (s1.size() != s2.size()) return false;

    return (s1 + s1).find(s2) != string::npos;
}

int main()
{
    cout << "Checking if waterbottle is a rotation of erbottlewat: " << isRotation("waterbottle", "erbottlewat") << endl;
    cout << "Checking if waterbottle is a rotation of rebottlewat: " << isRotation("waterbottle", "rebottlewat") << endl;
    cout << "Checking if waterbottle is a rotation of erbottlewa: " << isRotation("waterbottle", "erbottlewa") << endl;
}
