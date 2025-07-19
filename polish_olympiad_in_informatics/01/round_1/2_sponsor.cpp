/*
Task: Sponsor
Task author: Piotr Chrzastowski-Wachtel



Swimmer Daniel Waterproof has been sponsored by his uncle, a businessman, since
childhood. At the end of his sporting career, his uncle decided to award him a special
prize. Daniel has recorded all his times achieved during trainings and competitions in
his favorite discipline, namely 50 m freestyle. His uncle wants to give him an award
based on the length of the longest decreasing sequence of times that he can find in
not necessarily consecutive records. The amount of the prize is going to be a finite
multiple of the length of that sequence.

The input is a non-empty sequence of consecutively achieved results in Daniel’s career
recorded in seconds with precision reaching one thousandth of a second (0.001). Each
record is in the closed interval [20, 30]. Records can be separated from each other
with a single space or an end-line character.

The length of the found sequence shall be multiplied by 100.

The program shall return the price amount if the input values are correct or the word
NONSENSE otherwise.



Investigating the solution space
Let n be the number of all the records achieved by Daniel. If we assume that each
record is a switch that can be in one of two mutually exclusive states: included,
excluded, which indicates if a record is present in a potential result sequence, the
solution space can be calculated as 2 to the power of n. Checking each of the sequences
would require O(2 ^ n) time complexity.
We were given information that the records can fit into a closed interval of [20, 30]
and that the precision of the result is 0.001. Therefore, the sequence can be at most
10,000 elements long because 10 * 1,000. The key here is to track the finishing element
of a sequence of k elements and to acknowledge that it is optimal that this element is
the largest one.



Solution
Let’s create a concept of an array that stores the largest value that finishes a
sequence of k elements. Therefore, all preceding elements in the array are regressively
larger. After inserting all the last largest elements into that array, the index of the
last defined number will be the length of the shrinking sequence of time records, which
needs to be multiplied by 100.

Algorithm
1 Declare a table finishing_records[10000].
2 Declare a variable tracing the length of the defined elements in finishing_records.
3 Put the first time record to the first element of finishing_records array and update
  the length tracker.
4 FOR i := 1 TO record_count
  IF records[i] < finishing_records[defined_count - 1]
      4.1.1 finishing_records[defined_count] := records[i]
      4.1.2 defined_count := defined_count + 1
  ELSE
      4.2.1 Find the smallest index in finishing_records that
            finishing_records[j] <= records[i].
      4.2.2 Assign finishing_records[j] := records[i].
5 Calculate prize = 100 * defined_count.
To find the smallest index in step 4.2.1, use binary search.
Time complexity: O(n * log(n))
Space complexity: O(1)
*/

#define ENTRY_LEN 6
#define DEC_SEPARATOR '.'
#define DATA_FAILURE "NONSENSE"
#define SEQ_MAX 10000
#define PRIZE_MULTIPLIER 100
#include <cctype>
#include <iostream>

using namespace std;

bool is_valid_record(string &record_str)
{
    return record_str.length() == ENTRY_LEN
        && isdigit(record_str[0])
        && isdigit(record_str[1])
        && record_str[2] == DEC_SEPARATOR
        && isdigit(record_str[3])
        && isdigit(record_str[4])
        && isdigit(record_str[5]);
}

size_t find_index(const float *finishing_records, size_t defined_count, float record) 
{
    size_t left = 0, right = defined_count;
    do
    {
        size_t middle = (left + right) / 2;
        if (record < finishing_records[middle])
        {
            left = middle;
        }
        else
        {
            right = middle;
        }
    }
    while (left + 1 < right);
    return right;
}

int main()
{
    float finishing_records[SEQ_MAX];
    size_t defined_count = 0;
    string record_str;
    while (cin >> record_str)
    {
        if (is_valid_record(record_str))
        {
            const float record = stof(record_str);
            if (defined_count)
            {
                if (record < finishing_records[defined_count - 1])
                {
                    finishing_records[defined_count] = record;
                    ++defined_count;
                }
                else
                {
                    finishing_records[find_index(finishing_records, defined_count, record)] = record;
                }
            }
            else
            {
                finishing_records[defined_count] = record;
                ++defined_count;
            }
        }
        else
        {
            cout << DATA_FAILURE << endl;
            return 0;
        }
    }
    cout << PRIZE_MULTIPLIER * defined_count << endl;
    return 0;
}