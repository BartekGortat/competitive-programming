// https://szkopul.edu.pl/problemset/problem/RUEn3pvn1Jz4zSBlEhOXXoRE/site/?key=statement

#include <algorithm>
#include <iostream>
#include <list>

using namespace std;

bool order(int a, list<int> &nums)
{
    if (a)
    {
        auto iter = nums.begin();
        auto end = nums.end();
        for (int i = 0; i < a; ++i)
        {
            if (iter == end || *iter != i)
            {
                return false;
            }
            ++iter;
        }
        auto remove_end = ++iter;
        for (iter = nums.begin(); iter != remove_end; )
        {
            nums.erase(iter++);
        }
        return true;
    }
    else
    {
        return true;
    }
}

int main()
{
    int n;
    cin >> n;
    list<int> nums;
    while (n--)
    {
        int a;
        cin >> a;
        nums.push_back(a);
    }
    nums.sort();
    int min = nums.front();
    int max = nums.back();
    if (max)
    {
        if (!min)
        {
            for (int a = 0; a < max; ++a)
            {
                if (!order(a, nums))
                {
                    cout << (a + 1) << endl;
                    return 0;
                }
            }
            cout << (max + 1) << endl;
        }
        else
        {
            cout << 1 << endl;
        }
    }
    else
    {
        cout << 2 << endl;
    }
    return 0;
}
