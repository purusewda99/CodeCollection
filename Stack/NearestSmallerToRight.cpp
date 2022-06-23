#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

vector<int> nearestSmallerToRight(vector<int> &arr) {
    vector<int> v;
    stack<int> s;
    int n = arr.size();
    for(int i=n-1; i>=0; i--) {
        if(s.size() == 0)   v.push_back(-1);
        else if(s.size() > 0 && s.top() < arr[i]) {
            v.push_back(s.top());
        }
        else {
            while(s.size() > 0 && s.top() >= arr[i])
                s.pop();
            if(s.size() == 0)   v.push_back(-1);
            else    v.push_back(s.top());
        }
        s.push(arr[i]);
    }
    reverse(v.begin(), v.end());
    return v;
}

int main() {
    int n;
    cout << "Enter array size: ";
    cin >> n;
    vector<int> nums(n);
    cout << "Enter array: ";
    for(int i=0; i<n; i++) {
        int tmp;
        cin >> tmp;
        nums[i] = tmp;
    }

    vector<int> out = nearestSmallerToRight(nums);
    cout << "Output Array: ";
    for(auto x : out) {
        cout << x << " ";
    }
    return 0;
}