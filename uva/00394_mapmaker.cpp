// https://onlinejudge.org/external/3/394.pdf

#include <iostream>
#include <unordered_map>

using namespace std;

struct dimension_t
{
    int lower_bound;
    int upper_bount;
};

struct description_t
{
    int base_address;
    int element_size;
    int dimension_count;
    vector<dimension_t> dimensions;
};

int main()
{
    int n, r;
    cin >> n;
    cin >> r;
    unordered_map<string, description_t> descriptions;
    
    while (n--)
    {
        string name;
        cin >> name;
        description_t description;
        cin >> description.base_address;
        cin >> description.element_size;
        int dimension_count;
        cin >> dimension_count;
        description.dimension_count = dimension_count;
        while (dimension_count--)
        {
            dimension_t dimension;
            cin >> dimension.lower_bound;
            cin >> dimension.upper_bount;
            description.dimensions.push_back(dimension);
        }
        descriptions[name] = description;
    }
    while (r--)
    {
        string name;
        cin >> name;
        auto &description = descriptions.at(name);
        int address = description.base_address;
        vector<int> indices;
        for (int dim_idx = 0; dim_idx < description.dimension_count; ++dim_idx)
        {
            int idx;
            cin >> idx;
            indices.push_back(idx);
            int size = (idx - description.dimensions.at(dim_idx).lower_bound)
                * description.element_size;
            for (int follow_dim_idx = dim_idx + 1; follow_dim_idx < description.dimension_count; ++follow_dim_idx)
            {
                dimension_t &dimension = description.dimensions.at(follow_dim_idx);
                int dimension_count = dimension.upper_bount - dimension.lower_bound + 1;
                size *= dimension_count;
            }
            address += size;
        }
        cout << name << "[" << indices.at(0);
        for (int dim_idx = 1; dim_idx < description.dimension_count; ++ dim_idx)
        {
            cout << ", " << indices.at(dim_idx);
        }
        cout << "] = " << address << endl;
    }

    return 0;
}
