// https://onlinejudge.org/external/111/11173.pdf

#include <iostream>

using namespace std;

int main()
{
    int N, n, k;
    cin >> N;
    while (N)
    {
        cin >> n;
        cin >> k;

        int g = 1;
        g <<= (n - 1);

        bool indicator = true;
        int x = 0;
        while (g)
        {
            bool bottom = k >= g;
            int bit = bottom ? (indicator ? 1 : 0) : (indicator ? 0 : 1);
            if (bottom && indicator || !(bottom || indicator))
            {
                indicator = !indicator;
            }
            x <<= 1;
            x |= bit;
            k &= (g - 1);
            g >>= 1;
        }
        cout << x << endl;

        --N;
    }
    return 0;
}