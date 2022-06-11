// minimum number of operations to reduce x to exactly 0 if it is possible, 
// otherwise, return -1
#include<iostream>
#include<vector>
using namespace std;

#define INT_MAX 2147483647

int minOperations(vector<int>& nums, int x) {
    int sum = 0;
    int n = nums.size();
    for(int i=0;i<n;i++) {
        sum += nums[i];
    }

    if(sum < x) return -1;

    x -= sum;
    int l = n-1, r = n;
    int ans = INT_MAX;
    while(l >= 0) {

        if(x <= 0) {
            x += nums[l];
            l -= 1;
        }

        if(x > 0) {
            r -= 1;
            x -= nums[r];
        }

        if(x == 0) {
            ans = min(ans, l+1+n-r);
        }

    }

    return ans < INT_MAX ? ans : -1;
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

    int x;
    cout << "Enter X : ";
    cin >> x;

    int out = minOperations(nums, x);
    cout << out ;
    
    return 0;
}

// TC - O(n), SC - O(1)