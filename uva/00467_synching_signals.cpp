// https://onlinejudge.org/external/4/467.pdf

#include <algorithm>
#include <iostream>
#include <sstream>

using namespace std;

void increment_states(vector<int> &states, vector<int> &periods)
{
    for (auto state_iter = states.begin(), period_iter = periods.begin(); state_iter != states.end(); ++state_iter, ++period_iter)
    {
        int state = *state_iter;
        int period = *period_iter;
        int incremented_state = state + period;
        *state_iter = incremented_state;
    }
}

int main()
{
    int i = 0;
    string line;
    while (getline(cin, line, ' '))
    {
        if (line != "")
        {
            stringstream(line);
            string numeric_text;
            vector<int> periods;
            while (getline(line, numeric_text, ' '))
            {
                periods.push_back(stoi(numeric_text));
            }
            sort(periods.begin(), periods.end());
            vector<int> states(periods.size(), 0);
            increment_states(states, periods);
            increment_states(states, periods);
            int max_state = *max_element(states.begin(), states.end());
            increment_states(states, periods);
            int min_period = *min_element(states.begin(), states.end()) - 5;
            if (max_state <= min_period)
            {
                
            }
        }
        else
        {
            break;
        }
    }
    return 0;
}