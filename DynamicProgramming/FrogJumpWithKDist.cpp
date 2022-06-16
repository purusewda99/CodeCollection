/*Frog is allowed to jump up to ‘K’ steps at a time. 
If K=4, the frog can jump 1,2,3, or 4 steps at every index.
Your task is to find the minimum total energy used by the frog to reach from 1st stair to Nth stair.*/
#include<iostream>
#include<vector>
using namespace std;

#define INT_MAX 2147483647

int abs(int a, int b) {
    int diff = a-b;
    if(diff < 0)    diff = -diff;
    return diff;
}

int frogJumpUptoK(int n, vector<int>& nums, int k) {
    vector<int> dp(n, -1);
    dp[0] = 0;
    for(int i=1;i<n;i++) {
        int minSteps = INT_MAX;
        for(int j=1;j<=k;j++) {
            if(i-j>=0) {
                int jump = dp[i-j]+abs(nums[i], nums[i-j]);
                minSteps = min(minSteps, jump);
            }
        }
        dp[i] = minSteps;
    }
    return dp[n-1];
}

int main() {
    int n;
    cout << "Enter array size: ";
    cin >> n;
    vector<int> nums;
    cout << "Enter array: ";
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        nums.push_back(tmp);
    }
    int k;
    cout << "Enter k: ";
    cin >> k;

    int out = frogJumpUptoK(n, nums, k);
    cout << out ;
    return 0;
}

// Time Complexity - O(N*k)
// Space COmplexity - O(N)