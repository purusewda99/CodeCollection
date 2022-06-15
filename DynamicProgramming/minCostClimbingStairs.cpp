/* Minimum cost to reach the top of the floor. */
#include<iostream>
#include<vector>
using namespace std;

int minCostCLimbingStairs(vector<int>& cost) {
    int n = cost.size();
    vector<int> dp(n);
    for(int i=0;i<n;i++) {
        if(i<2) dp[i] = cost[i];
        else    dp[i] = cost[i]+min(dp[i-1], dp[i-2]);
    }
    return min(dp[n-1], dp[n-2]);
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

    int out = minCostCLimbingStairs(nums);
    cout << out ;
    return 0;
}