// Collections of candidate numbers and a target
// any combination whose sum is target
// each number in candidate may only be used once
// no duplicate combinations
#include<iostream>
#include<vector> 
#include<algorithm>
using namespace std;

void combination(vector<vector<int>>& vec, int i, vector<int>& candidates, int target, vector<int>& ans) {
    if(target == 0) {
        vec.push_back(ans);
    }
    for(int j=i;j<candidates.size();j++) {
        if(j>i && candidates[j] == candidates[j-1]) continue;
        if(candidates[j] > target)  break;
        ans.push_back(candidates[j]);
        combination(vec, j+1, candidates, target-candidates[j], ans);
        ans.pop_back();
    }
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> vec;
    vector<int> ans;
    combination(vec, 0, candidates, target, ans);
    return vec;
}

int main() {
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

    vector<vector<int>> out = combinationSum2(candidates, target);
    for(int i=0;i<out.size();i++) {
        for(int j=0;j<out[i].size();j++) {
            cout << out[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}