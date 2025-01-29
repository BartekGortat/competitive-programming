// https://szkopul.edu.pl/problemset/problem/Sw51M4n8a9sGQ4QF2zG7NxRv/site/?key=statement

#include <iostream>
#include <stack>

using namespace std;

int main()
{
    string line;
    cin >> line;
    stack<int> indices;
    char increase_bit;
    int max_len = 0;
    int line_len = line.size();
    int last_begin_index = 0;
    int last_end_index = - 1;
    for (int index = 0; index < line_len; ++index)
    {
        auto bit = line.at(index);
        if (indices.empty())
        {
            increase_bit = bit;
        }
        if (bit == increase_bit)
        {
            indices.push(index);
        }
        else
        {
            auto begin_index = indices.top();
            indices.pop();
            bool continuous = begin_index - 1 == last_end_index;
            int len = continuous
                ? index - last_begin_index + 1
                : index - begin_index + 1;
            if (len > max_len)
            {
                last_end_index = index;
                max_len = len;
                if (!continuous)
                {
                    last_begin_index = begin_index;
                }
            }
        }
    }
    cout << max_len << endl;
    return 0;
}
