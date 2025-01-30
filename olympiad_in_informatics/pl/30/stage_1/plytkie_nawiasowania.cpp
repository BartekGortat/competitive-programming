// https://szkopul.edu.pl/problemset/problem/KlznBqTfieN-sWvUfTD0BJdT/site/?key=statement
// Result: 100/100

#include <iostream>
#include <list>
#include <stack>
#include <utility>

using namespace std;

int main()
{
    int n; // character count
    int h; // depth
    string brackets;
    cin >> n >> h >> brackets;
    int amendment_count = 0;
    int depth = 0;
    for (char bracket : brackets)
    {
        if (bracket == '(')
        {
            ++depth;
            if (depth > h)
            {
                ++amendment_count;
                depth -= 2;
            }
        }
        else
        {
            --depth;
            if (depth < 0)
            {
                ++amendment_count;
                depth = 1;
            }
        }
    }
    cout << amendment_count << endl;
    return 0;
}