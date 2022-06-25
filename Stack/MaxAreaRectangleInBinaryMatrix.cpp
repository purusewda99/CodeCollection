// It is variation of Maximum Area Histogram
#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

#define INT_MIN -2147483648

vector<int> nearestSmallerToLeft(vector<int> &arr) {
    vector<int> v;
    int n = arr.size();
    stack<int> s;
    int pseudoIndx = -1;
    for(int i=0; i<n; i++) {
        if(s.size() == 0)   v.push_back(pseudoIndx);
        else if(s.size()>0 && arr[s.top()]<arr[i])
            v.push_back(s.top());
        else {
            while(s.size()>0 && arr[s.top()]>=arr[i])
                s.pop();
            if(s.size() == 0)   v.push_back(pseudoIndx);
            else    v.push_back(s.top());
        }
        s.push(i);
    }
    return v;
}

vector<int> nearestSmallerToRight(vector<int> &arr) {
    vector<int> v;
    int n = arr.size();
    stack<int> s;
    int pseudoIndx = n;
    for(int i=n-1; i>=0; i--) {
        if(s.size() == 0)   v.push_back(pseudoIndx);
        else if(s.size()>0 && arr[s.top()]<arr[i])
            v.push_back(s.top());
        else {
            while(s.size()>0 && arr[s.top()]>=arr[i])
                s.pop();
            if(s.size() == 0)   v.push_back(pseudoIndx);
            else    v.push_back(s.top());
        }
        s.push(i);
    }
    reverse(v.begin(), v.end());
    return v;
}

int maxAreaHistogram(vector<int> arr) {
    vector<int> left = nearestSmallerToLeft(arr);
    vector<int> right = nearestSmallerToRight(arr);

    int n = arr.size();
    int mx = INT_MIN;
    for(int i=0; i<n; i++) {
        right[i] -= (left[i]+1);
        right[i] *= arr[i];
        mx = max(mx, right[i]);
    }
    return mx;
}

int maxAreaReactangleInBinaryMatrix(vector<vector<int>> &arr) {
    vector<int> vec;
    for(int j=0;j<arr[0].size();j++) {
        vec.push_back(arr[0][j]);
    }
    int mxArea = maxAreaHistogram(vec);
    for(int i=1;i<arr.size();i++) {
        for(int j=0;j<arr[i].size();j++) {
            if(arr[i][j] == 0)  vec[j]=0;
            else    vec[j] += arr[i][j];
        }
        mxArea = max(mxArea, maxAreaHistogram(vec));
    }
    return mxArea;
}

int main() {
    int n;
    cout << "Enter row size: ";
    cin >> n;
    int m;
    cout << "Enter column size: ";
    cin >> m;
    vector<vector<int>> arr(n, vector<int> (m));
    for(int i=0; i<n; i++) {
        cout << "Enter array " << i << "th row: ";
        for(int j=0; j<m; j++) {     
            int tmp;
            cin >> tmp;
            arr[i][j] = tmp;
        }
    }

    int mxA = maxAreaReactangleInBinaryMatrix(arr);
    cout << mxA;
    return 0;
}