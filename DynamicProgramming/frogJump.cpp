/*If Frog jumps from ith to jth stair, the energy lost in the jump is given by |HEIGHT[i-1] - HEIGHT[j-1] |.
In the Frog is on ith staircase, he can jump either to (i+1)th stair or to (i+2)th stair. 
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

int frogJump(int n, vector<int> &heights) {
    int prev = 0;
    int prev2 = 0;
    for(int i=1;i<n;i++) {
        int fs = prev+abs(heights[i], heights[i-1]);
        int ss = INT_MAX;
        if(i>1) ss = prev2+abs(heights[i], heights[i-2]);
        int cur = min(fs, ss);
        prev2 = prev;
        prev = cur;
    }
    return prev;
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

    int out = frogJump(n, nums);
    cout << out ;
    return 0;
}

// Time Complexity - O(N)
// Space COmplexity - O(1)