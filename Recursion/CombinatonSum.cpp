// print all combinations whose sum = target
// but array is made of distinct integers
// and in combination duplicates are allowed
#include <iostream>
#include <vector>
using namespace std;

void combination(vector<vector<int>> &res, vector<int> &candidates, int target,
                 int sum, int indx, vector<int> &subarr)
{

    if (sum == target)
    {
        res.push_back(subarr);
        return;
    }

    if (indx >= (candidates.size()))
    {
        return;
    }

    if (sum > target)
        return;

    sum += candidates[indx];
    subarr.push_back(candidates[indx]);
    combination(res, candidates, target, sum, indx, subarr);

    sum -= candidates[indx];
    subarr.pop_back();
    combination(res, candidates, target, sum, indx + 1, subarr);
}

vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
    vector<vector<int>> res;
    vector<int> subarr;
    combination(res, candidates, target, 0, 0, subarr);
    return res;
}

int main()
{
    int n;
    cout << "Enter array size: ";
    cin >> n;
    vector<int> candidates;
    cout << "Enter array: ";
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        candidates.push_back(tmp);
    }

    int target;
    cout << "Enter Sum: ";
    cin >> target;

    vector<vector<int>> out = combinationSum(candidates, target);
    for(int i=0;i<out.size();i++) {
        for(int j=0;j<out[i].size();j++) {
            cout << out[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}