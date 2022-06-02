// Print all permutations of a string/array
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// method 2 - Backtracking
// TC -> O(n!*n)
// SC -> only auxiliary space of recursion -> O(n)
void permuteBacktrackFunc(int ind, vector<int> &nums,
                          vector<vector<int>> &ans)
{
    if (ind == nums.size())
    {
        ans.push_back(nums);
        return;
    }
    for (int i = ind; i < nums.size(); i++)
    {
        swap(nums[ind], nums[i]);
        permuteBacktrackFunc(ind + 1, nums, ans);
        swap(nums[ind], nums[i]);
    }
}

vector<vector<int>> permuteBacktracking(vector<int> &nums)
{
    vector<vector<int>> ans;
    permuteBacktrackFunc(0, nums, ans);
    return ans;
}

// method 1 - Recursion
// TC-> O(n!*n)
// SC-> O(n)+O(n), auxiliary space -> O(n)
void permuteRecurFunc(vector<int> &ds, vector<int> &nums,
                      vector<vector<int>> &ans, vector<int> freq)
{
    if (ds.size() == nums.size())
    {
        ans.push_back(ds);
        return;
    }
    for (int i = 0; i < nums.size(); i++)
    {
        if (!freq[i])
        {
            ds.push_back(nums[i]);
            freq[i] = 1;
            permuteRecurFunc(ds, nums, ans, freq);
            freq[i] = 0;
            ds.pop_back();
        }
    }
}

vector<vector<int>> permuteRecursion(vector<int> &nums)
{
    vector<vector<int>> ans;
    vector<int> ds;
    vector<int> freq(nums.size(), 0);
    permuteRecurFunc(ds, nums, ans, freq);
    return ans;
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

    // method 1 - Recursion
    // vector<vector<int>> out = permuteRecursion(arr);

    // method 2 - Backtracking
    vector<vector<int>> out = permuteBacktracking(arr);

    for (int i = 0; i < out.size(); i++)
    {
        for (int j = 0; j < out[i].size(); j++)
        {
            cout << out[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}