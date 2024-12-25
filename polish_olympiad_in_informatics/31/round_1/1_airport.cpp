// https://szkopul.edu.pl/problemset/problem/E0WdV0P4l3hYG2WAuFWyQ-TV/site/?key=statement

#include <iostream>
#include <map>
#include <vector>

using namespace std;

struct line_t
{
    int i;
    int j;
    int len;
};

int main()
{
    int n, m;
    cin >> n;
    cin >> m;
    int fields[n][n];
    for (int i = 0; i < n; ++i)
    {
        string line;
        cin >> line;
        for (int j = 0; j < n; ++j)
        {
            fields[i][j] = line.at(j) == '.' ? 0 : 1;
        }
    }
    map<int, vector<line_t>> horizontal_lines;
    for (int i = 0; i < n; ++i)
    {
        int begin_index = -1;
        for (int j = 0; j < n; ++j)
        {
            if (fields[i][j])
            {
                if (begin_index >= 0)
                {
                    int len = j - begin_index;
                    line_t line;
                    line.i = i;
                    line.j = begin_index;
                    line.len = len;
                    horizontal_lines[len].push_back(line);
                    begin_index = -1;
                }
            }
            else
            {
                if (begin_index == -1)
                {
                    begin_index = j;
                }
            }
        }
        if (begin_index >= 0)
        {
            int len = n - begin_index;
            line_t line;
            line.i = i;
            line.j = begin_index;
            line.len = len;
            horizontal_lines[len].push_back(line);
        }
    }
    map<int, vector<line_t>> vertical_lines;
    for (int j = 0; j < n; ++j)
    {
        int begin_index = -1;
        for (int i = 0; i < n; ++i)
        {
            if (fields[i][j])
            {
                if (begin_index >= 0)
                {
                    int len = i - begin_index;
                    line_t line;
                    line.i = begin_index;
                    line.j = j;
                    line.len = len;
                    vertical_lines[len].push_back(line);
                    begin_index = -1;
                }
            }
            else
            {
                if (begin_index == -1)
                {
                    begin_index = i;
                }
            }
        }
        if (begin_index >= 0)
        {
            int len = n - begin_index;
            line_t line;
            line.i = begin_index;
            line.j = j;
            line.len = len;
            vertical_lines[len].push_back(line);
        }
    }
    for (auto iter = vertical_lines.begin(); iter != vertical_lines.end(); ++iter)
    {
        auto &lines = iter->second;
        for (auto line : lines)
        {
            cout << "(i=" << line.i << ", j=" << line.j << "), len = " << line.len << endl;
        }
    }
    return 0;
}