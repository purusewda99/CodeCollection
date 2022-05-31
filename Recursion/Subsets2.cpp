// All subsets without the duplicates
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void subsetFunc(vector<vector<int>> &res, vector<int> &subset,
                vector<int> nums, int ind)
{
    if (ind == nums.size())
    {
        res.push_back(subset);
        return;
    }
    res.push_back(subset);
    for (int i = ind; i < nums.size(); i++)
    {
        if (i > ind && nums[i] == nums[i - 1])
            continue;
        subset.push_back(nums[i]);
        subsetFunc(res, subset, nums, i + 1);
        subset.pop_back();
    }
}
vector<vector<int>> subsetsWithDup(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;
    vector<int> subset;
    subsetFunc(res, subset, nums, 0);
    return res;
}

int main()
{
    int n;
    cout << "Enter array size: ";
    cin >> n;
    vector<int> arr;
    cout << "Enter array: ";
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        arr.push_back(tmp);
    }

    vector<vector<int>> out = subsetsWithDup(arr);
    for(int i=0;i<out.size();i++) {
        for(int j=0;j<out[i].size();j++) {
            cout << out[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

// Time Complexity -> O((2^n)*n)
// Space Complexity -> O((2*n) *K) K-> avg. length of subsets
// Auxiliary Space -> O(n)
