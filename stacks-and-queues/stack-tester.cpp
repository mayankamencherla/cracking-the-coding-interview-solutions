#include "stack.cpp"
#include <iostream>

using namespace std;

int main()
{
    vector<int> v = {1, 2, 3, 4, 5};

    Stack s = Stack(v);

    while (s.size() > 0)
    {
        cout << "Popping the top element : " << s.pop() << endl;
    }
}
