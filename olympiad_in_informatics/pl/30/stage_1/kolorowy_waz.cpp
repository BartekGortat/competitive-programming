// https://szkopul.edu.pl/problemset/problem/GzVKpGwP7huOf_gNK4ZnIPn1/site/?key=statement
// Result: 100/100

#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int main()
{
    int m; // board dimension
    int p; // food count
    int n; // command count
    cin >> m >> p >> n;
    int board[m][m];
    int food[m][m];
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            board[i][j] = -1;
            food[i][j] = -1;
        }
    }
    int snake_max_len = p + 1;
    int snake_colors[snake_max_len]; // color, step
    while (p--)
    {
        int w; // row index
        int k; // column index
        int c; // color
        cin >> w >> k >> c;
        food[--w][--k] = c;
    }
    queue<pair<int, int>> snake_locations; // row, column
    board[0][0] = 0;
    snake_locations.push(make_pair(0, 0));
    int step = 0;
    int snake_len = 0;
    snake_colors[snake_len] = 0;
    ++snake_len;
    while (n--)
    {
        char command;
        cin >> command;
        if (command == 'Z')
        {
            int w; // row index
            int k; // column index
            cin >> w >> k;
            int head_step = board[--w][--k];
            int elapsed_step_count = step - head_step;
            if (elapsed_step_count < snake_len)
            {
                cout << snake_colors[snake_len - 1 - elapsed_step_count] << endl;
            }
            else
            {
                cout << "-1" << endl;
            }
        }
        else
        {
            ++step;
            auto head_location = snake_locations.back();
            switch (command)
            {
                case 'G':
                    --head_location.first;
                    break;
                case 'D':
                    ++head_location.first;
                    break;
                case 'L':
                    --head_location.second;
                    break;
                case 'P':
                    ++head_location.second;
                    break;
            }
            auto tail_location = snake_locations.front();
            auto &food_color = food[head_location.first][head_location.second];
            if (food_color != -1)
            {
                snake_colors[snake_len] = food_color;
                ++snake_len;
                food_color = -1;
            }
            else
            {
                snake_locations.pop();
                board[tail_location.first][tail_location.second] = -1;
            }
            board[head_location.first][head_location.second] = step;
            snake_locations.push(head_location);
        }
    }

    return 0;
}