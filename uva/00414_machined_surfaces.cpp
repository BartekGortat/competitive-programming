// https://onlinejudge.org/external/4/414.pdf

#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

int main()
{
    while (true)
    {
        int N;
        cin >> N;
        if (N)
        {
            vector<size_t> empty_counts;
            while (N--)
            {
                string line;
                cin >> line;
                size_t empty_count = count_if(line.begin(), line.end(), [](char ch) { return ch == ' '; });
                empty_counts.push_back(empty_count);
            }
            size_t reduction = *min_element(empty_counts.begin(), empty_counts.end());
            size_t count_sum = accumulate(empty_counts.begin(), empty_counts.end(), 0);
            size_t reduced_count = count_sum - reduction * empty_counts.size();
            cout << reduced_count << endl;
        }
        else
        {
            break;
        }
    }
    return 0;
}