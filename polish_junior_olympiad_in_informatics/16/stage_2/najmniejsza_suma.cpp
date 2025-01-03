// https://szkopul.edu.pl/problemset/problem/STjOFeUHMP1RSUi81siSWe7O/site/?key=statement

#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

int take_first(vector<int> &counts, int last_digit)
{
    for (int i = last_digit; i < 10; ++i)
    {
        auto &count = counts[i];
        if (count)
        {
            --count;
            return i;
        }
    }
    return -1;
}

int main()
{
    string digit_seq;
    int word_count;
    cin >> digit_seq >> word_count;
    vector<int> counts = vector<int>(10, 0);
    for (auto &ch : digit_seq)
    {
        int digit = ch - 48;
        ++counts[digit];
    }
    int digit_count = digit_seq.size();
    int full_word_len = digit_count / word_count;
    int partial_word_len = digit_count % word_count;
    if (partial_word_len)
    {
        ++full_word_len;
    }
    int empty_len = full_word_len - partial_word_len;
    vector<int> nums = vector<int>(word_count, 0);
    int last_leading_digit = 1;
    int last_following_digit = 0;
    if (partial_word_len)
    {
        int full_word_count = word_count - 1;
        int partial_word_count = 1;
        for (int i = 0; i < full_word_count; ++i)
        {
            last_leading_digit = take_first(counts, last_leading_digit);
            nums[i] = last_leading_digit;
        }
        for (int j = 0; j < empty_len; ++j)
        {
            for (int i = 0; i < full_word_count; ++i)
            {
                last_following_digit = take_first(counts, last_following_digit);
                nums[i] *= 10;
                nums[i] += last_following_digit;
            }
        }
        last_leading_digit = take_first(counts, last_leading_digit);
        nums[word_count - 1] = last_leading_digit;
        for (int j = 1; j < partial_word_len; ++j)
        {
            for (int i = 0; i < word_count; ++i)
            {
                last_following_digit = take_first(counts, last_following_digit);
                nums[i] *= 10;
                nums[i] += last_following_digit;
            }
        }
    }
    else
    {
        for (int i = 0; i < word_count; ++i)
        {
            last_leading_digit = take_first(counts, last_leading_digit);
            nums[i] = last_leading_digit;
        }
        for (int j = 1; j < full_word_len; ++j)
        {
            for (int i = 0; i < word_count; ++i)
            {
                last_following_digit = take_first(counts, last_following_digit);
                nums[i] *= 10;
                nums[i] += last_following_digit;
            }
        }
    }

    cout << accumulate(nums.begin(), nums.end(), 0) << endl;

    return 0;
}
