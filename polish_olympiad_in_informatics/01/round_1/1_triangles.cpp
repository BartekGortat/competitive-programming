/*
Task: Triangles
Task author: Piotr Chrzastowski-Wachtel



Let there be a finite set A containing at least 3 elements. Each element describes the
length of a line segment expressed as a ratio of two integer numbers. You are going to
investigate if you can build triangles of all the line segments contained in A.

The input data is a sequence of at least 3 elements. Each of them represents the length
of a line segment. Each length is written in the form of numerator/denominator, where
the numerator and the denominator are positive integer numbers not greater than 9999.

Two consecutive lengths in the sequence are separated from each other with a single
space or a new line character.

You need to return YES if triangles can be made of all the elements of A.
You need to return NO if there exists a triplet of which a triangle cannot be built.
You need to return NONSENSE if the input data contain a value that does not meet the
input criteria.



The key to solving the task is the triangle inequality, which states that in order to
build a triangle, the following inequality must be preserved for each of its line
segment lengths: a + b > c.
Since a collection of line segment lengths is given, it can be sorted and assumed that:
a is the shortest line segment length,
b is the second shortest line segment length,
c is the longest line segment length.

If the triangle inequality is preserved for the above length triplet, it must be
preserved for all other triplets. To prove that, let's assume that there are n triplets
formed from all the line segments in the set: (a_1, b_1, c_1), ..., (a_n, b_n, c_n);
and that triplet 1 contains the shortest, second shortest, and longest line segment
lengths: for k >= 2 AND k <= n: a_1 <= a_k, b_1 <= b_k, c_1 >= c_k. If the triangle
inequality holds for triplet 1, it also holds for triplet k because:
a) since c_k <= c_1, you get the following inequality: a_1 + b_1 > c_k
b) since a_k >= a_1 AND b_k >= b_1, you get the following inequality: a_k + b_k > c_1
c) since c_k <= c_1, you get the following inequality: a_k + b_k > c_k
All the possibilities have been exhausted in the three points above, and it ends the
proof.

Algorithm
1. Sort all the line segment lengths.
2. Get the shortest (a), the second shortest (b), and the longest (c) line segments.
3. Check if the triangle inequality holds. a + b > c
   3.1. If yes, claim success.
   3.2. Otherwise, claim failure.
*/

#define CLAIM_SUCCESS() \
    cout << "YES" << endl;

#define CLAIM_FAILURE() \
    cout << "NO" << endl;

#define CLAIM_NONSENSE() \
    cout << "NONSENSE" << endl;

#define SEPARATOR "/"
#define MAX_LEN 4

#include <cctype>
#include <iostream>
#include <list>

using namespace std;

struct element_t
{
    int numerator;
    int denominator;

    element_t(int numerator, int denominator) : numerator{numerator}, denominator{denominator}
    {
    }

    bool operator <(const element_t &compared) const
    {
        if (denominator != compared.denominator)
        {
            return numerator * compared.denominator < compared.numerator * denominator;
        }
        else
        {
            return numerator < compared.numerator;
        }
    }
};

bool only_digit(string s)
{
    const auto len = s.length();
    if (len && len <= MAX_LEN)
    {
        for (auto &ch : s)
        {
            if (!isdigit(ch))
            {
                return false;
            }
        }
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    string element;
    list<element_t> line_segments;
    while (cin >> element)
    {
        const auto separator_idx = element.find(SEPARATOR);
        if (separator_idx != string::npos
            && element.find(SEPARATOR, separator_idx + 1) == string::npos)
        {
            const auto numerator_s = element.substr(0, separator_idx);
            const auto denomicator_s = element.substr(separator_idx + 1);
            if (only_digit(numerator_s) && only_digit(denomicator_s))
            {
                const auto numerator = stoi(numerator_s);
                const auto denominator = stoi(denomicator_s);
                if (denominator)
                {
                    line_segments.push_back(element_t(numerator, denominator));
                }
                else
                {
                    CLAIM_NONSENSE()
                    return 0;
                }
            }
            else
            {
                CLAIM_NONSENSE()
                return 0;
            }
        }
        else
        {
            CLAIM_NONSENSE()
            return 0;
        }
    }
    line_segments.sort();
    auto left_iter = line_segments.begin();
    const auto &shortest = *left_iter;
    ++left_iter;
    const auto &second_shortest = *left_iter;
    const auto &longest = *line_segments.rbegin();
    const auto a = shortest.numerator * second_shortest.denominator * longest.denominator;
    const auto b = shortest.denominator * second_shortest.numerator * longest.denominator;
    const auto c = shortest.denominator * second_shortest.denominator * longest.numerator;
    if (a + b > c)
    {
        CLAIM_SUCCESS();
    }
    else
    {
        CLAIM_FAILURE();
    }

    return 0;
}