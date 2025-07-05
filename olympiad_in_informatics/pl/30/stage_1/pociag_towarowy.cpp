// https://szkopul.edu.pl/problemset/problem/U5dJG9pa-TT5cl-5Fkf8SrwB/site/?key=statement
// 20/100

#include <iostream>
#include <unordered_set>

using namespace std;

int main()
{
    int n; // Bajtek's cound
    int m; // Bitek's count
    int k; // color count
    cin >> n >> m >> k;
    int complete_wagons[n];
    int partial_wagons[m];
    unordered_set<int> partial_colors;
    for (int i = 0; i < n; ++i)
    {
        int wagon;
        cin >> wagon;
        complete_wagons[i] = wagon;
    }
    for (int i = 0; i < m; ++i)
    {
        int wagon;
        cin >> wagon;
        partial_wagons[i] = wagon;
        partial_colors.insert(wagon);
    }
    bool potential_wagon_markers[n];
    for (int i = 0; i < n; ++i)
    {
        potential_wagon_markers[i] = false;
    }
    int complete_index = 0;
    int partial_index = 0;
    int last_progressive_index = n - 1;
    while (partial_index < m)
    {
        int complete_wagon = complete_wagons[complete_index];
        int partial_wagon = partial_wagons[partial_index];
        if (complete_wagon == partial_wagon)
        {
            potential_wagon_markers[complete_index] = true;
            last_progressive_index = complete_index;
            ++partial_index;
        }
        ++complete_index;
    }
    complete_index = n - 1;
    partial_index = m - 1;
    int first_regressive_index = 0;
    while (partial_index >= 0)
    {
        int complete_wagon = complete_wagons[complete_index];
        int partial_wagon = partial_wagons[partial_index];
        if (complete_wagon == partial_wagon)
        {
            potential_wagon_markers[complete_index] = true;
            first_regressive_index = complete_index;
            --partial_index;
        }
        --complete_index;
    }
    for (int i = last_progressive_index + 1; i < first_regressive_index; ++i)
    {
        int wagon = complete_wagons[i];
        if (partial_colors.count(wagon))
        {
            potential_wagon_markers[i] = true;
        }
    }
    for (int i = 0; i < n; ++i)
    {
        cout << potential_wagon_markers[i] << " ";
    }
    cout << endl;
    return 0;
}