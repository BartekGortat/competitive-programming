// https://onlinejudge.org/external/5/507.pdf
// The following solution uses a recursive approach.
// Onther approaches are also possible.

#include <cstdio>
#include <vector>

using namespace std;

struct route_t
{
    int begin_index;
    int end_index;
    int cumulated_nice_level;
};

int main()
{
    int route_count;
    scanf("%d", &route_count);
    for (int route_index = 1; route_index <= route_count; ++route_index)
    {
        int stop_count;
        scanf("%d", &stop_count);
        vector<int> nice_levels(stop_count);
        nice_levels[0] = 0;
        for (int stop_index = 1; stop_index < stop_count; ++stop_index)
        {
            int nice_level;
            scanf("%d", &nice_level);
            nice_levels[stop_index] = nice_level;
        }
    }
    return 0;
}