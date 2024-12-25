// https://szkopul.edu.pl/problemset/problem/4fZ2-3xPeFQ8FGorVx6j84oe/site/?key=statement
// partially solved

#define FILLED 'X'
#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    string queue;
    cin >> queue;
    int delay = -1;
    int time = 0;
    for (int i = n - 1; i >= 0; --i)
    {
        if (queue.at(i) == FILLED)
        {
            int distance = n - i;
            ++delay;
            time = distance + delay;
        }
    }
    cout << time << endl;
    return 0;
}
