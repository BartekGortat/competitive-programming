// https://szkopul.edu.pl/problemset/problem/9y5Fywu8h7DyO89-gd5ifrju/site/?key=statement
// score 100/100

#include <climits>
#include <iostream>
#include <list>
#include <unordered_map>

using namespace std;

int main()
{
    int n, a;
    cin >> n;
    unordered_map<int, list<int>> records;
    int min_len = INT_MAX;
    while (n--)
    {
        cin >> a;
        auto &indices = records[a];
        indices.push_back(n);
        if (indices.size() == 3)
        {
            int len = indices.front() - n;
            if (len < min_len)
            {
                min_len = len;
            }
            indices.pop_front();
        }
    }
    if (min_len == INT_MAX)
    {
        cout << "NIE" << endl;
    }
    else
    {
        cout << min_len + 1 << endl;
    }

    return 0;
}
