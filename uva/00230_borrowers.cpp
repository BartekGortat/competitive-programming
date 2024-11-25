// https://onlinejudge.org/external/2/230.pdf

#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

struct book_t
{
    string author;
    string title;
    bool lent;
};

bool compare(const book_t &left, const book_t &right)
{
    auto result = left.author.compare(right.author);
    return result < 0 ? true
        : result > 0 ? false
        : left.title.compare(right.title) < 0 ? true
        : false;
}

int main()
{
    vector<book_t> books;
    string line;

    getline(cin, line);
    while (line != "END")
    {
        auto close_quote_idx = line.find_last_of("\"");
        auto title_len = close_quote_idx + 1;
        string title = line.substr(0, title_len);
        auto author_idx = close_quote_idx + 5;
        auto author_len = line.length() - author_idx;
        string author = line.substr(author_idx, author_len);
        books.push_back({author, title, false});
        getline(cin, line);
    }
    sort(books.begin(), books.end(), compare);

    map<string, vector<book_t>::iterator> index;
    const auto book_end = books.end();
    for (auto iter = books.begin(); iter != book_end; ++iter)
    {
        index[iter->title] = iter;
    }

    getline(cin, line);
    while (line != "END")
    {
        if (line != "SHELVE")
        {
            string action = line.substr(0, 6);
            string title = line.substr(7, line.length());
            if (action == "BORROW")
            {
                index[title]->lent = true;
            }
        }
        else
        {
            string previous_title{""};
            for (auto &book : books)
            {
                if (book.lent)
                {
                    book.lent = false;
                    if (previous_title != "")
                    {
                        printf("Put %s after %s\n", book.title.c_str(), previous_title.c_str());
                    }
                    else
                    {
                        printf("Put %s first\n", book.title.c_str());
                    }
                }
                previous_title = book.title;
            }
            printf("END\n");
        }
        getline(cin, line);
    }
    
    return 0;
}