// https://szkopul.edu.pl/problemset/problem/7eqW4uZFWN1pjgtGVjU_U2h5/site/?key=statement
// score 100/100

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    string line;
    int k;
    cin >> line >> k;
    vector<int> locations;
    int l = line.size();
    for (int i = 0; i < l; ++i)
    {
        if (line.at(i) == 'X')
        {
            locations.push_back(i);
        }
    }
    int last_left_index = locations.size() - k;
    int shift = k - 1;
    double min_distance = 200000.0;
    for (int left_index = 0; left_index <= last_left_index; ++left_index)
    {
        int right_index = left_index + shift;
        double left = locations.at(left_index);
        double right = locations.at(right_index);
        double distance = (right - left) / 2.0;
        if (distance < min_distance)
        {
            min_distance = distance;
        }
    }
    cout << min_distance << endl;
    return 0;
}