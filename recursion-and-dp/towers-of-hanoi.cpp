/**
 * Given 2 numbers, recursively multiply them
 * Without using *, use +, -, >>, <<
 * Minimize the operations listed above
 */

#include <vector>
#include <iostream>
#include <stack>

using namespace std;

void initializeMain(stack<int>& main, int n)
{
    for (int i=n; i>=1; i--)
    {
        main.push(i);
    }
}

void moveStacks(stack<int>& main, stack<int>& buffer, int n)
{
    while (n > 0)
    {
        buffer.push(main.top());

        main.pop();

        n--;
    }
}

void moveLargestElement(stack<int>& main, stack<int>& target)
{
    int top = main.top();

    main.pop();

    target.push(top);
}

void towersOfHanoi(stack<int>& main, stack<int>& buffer, stack<int>& target, int n)
{
    if (n <= 0) return;

    towersOfHanoi(main, target, buffer, n-1);

    moveLargestElement(main, target);

    towersOfHanoi(buffer, main, target, n-1);
}

int main()
{
    stack<int> main;

    stack<int> buffer;

    stack<int> target;

    int n;

    printf("Enter any number : ");

    cin >> n;

    initializeMain(main, n);

    towersOfHanoi(main, buffer, target, n);

    while (!target.empty())
    {
        cout << target.top() << endl;

        target.pop();
    }
}
