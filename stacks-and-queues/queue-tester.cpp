#include "queue.cpp"
#include <iostream>

using namespace std;

int main()
{
    vector<int> v = {1, 2, 3, 4, 5};

    Queue q = Queue(v);

    while (q.size() > 0)
    {
        cout << "Popping the front element : " << q.pop() << endl;
    }
}
