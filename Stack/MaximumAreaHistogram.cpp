// Area of the largest rectangle in the histogram
#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

#define INT_MIN -2147483648

int maximumAreaHistogram(vector<int> &arr) {
    int n = arr.size();
    vector<int> v(n);
    stack<int> s;

    // Nearest Smaller to Right
    int pseudoIndx = n;
    for(int i=n-1; i>=0; i--) {
        if(s.size() == 0)
            v.push_back(pseudoIndx);
        else if(s.size() > 0 && arr[s.top()] < arr[i]) 
            v.push_back(s.top());
        else {
            while(s.size() > 0 && arr[s.top()] >= arr[i])
                s.pop();
            if(s.size() == 0)   
                v.push_back(pseudoIndx);
            else
                v.push_back(s.top());
        }
        s.push(i);
    }
    reverse(v.begin(), v.end());

    while(!s.empty())   s.pop();

    int j=0;
    pseudoIndx = -1;
    // Nearest Smaller to left
    for(int i=0; i<n; i++) {
        if(s.size() == 0) {
            // width vector
            v[j] = v[j]-pseudoIndx-1;
            j++;
        }
        else if(s.size() > 0 && arr[s.top()] < arr[i]) {
            // width vector
            v[j] = v[j]-s.top()-1;
            j++;
        }
        else {
            while(s.size() > 0 && arr[s.top()] >= arr[i])
                s.pop();
            if(s.size() == 0) {
                // width vector
                v[j] = v[j]-pseudoIndx-1;
                j++;
            }
            else {
                // width vector
                v[j] = v[j]-s.top()-1;
                j++;
            }
        }
        s.push(i);
    }

    int mx = INT_MIN;
    // area vector
    for(int i=0; i<n; i++) {
        v[i] *= arr[i];
        mx = max(mx, v[i]);
    }

    return mx;
}

int main() {
    int n;
    cout << "Enter array size: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter array: ";
    for(int i=0; i<n; i++) {
        int tmp;
        cin >> tmp;
        arr[i] = tmp;
    }

    int mxArea = maximumAreaHistogram(arr);
    cout << "Output: " << mxArea;
    return 0;
}