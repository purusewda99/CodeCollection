// aka Nearest Smaller to Left
#include<iostream> 
#include<vector>
#include<stack>
using namespace std;

vector<int> nextLargestElement(vector<int> &arr) {
    vector<int> v;
    stack<int> s;
    int n = arr.size();
    for(int i=0; i<n; i++) {
        if(s.size() == 0)   v.push_back(-1);
        else if(s.size() > 0 && s.top() < arr[i]) {
            v.push_back(s.top());
        }
        else {
            while (s.size() > 0 && s.top() >= arr[i])
                s.pop();
            if(s.size() == 0)   v.push_back(-1);
            else    v.push_back(s.top());
        }
        s.push(arr[i]);
    }
    return v;
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

    vector<int> out = nextLargestElement(arr);
    cout << "Output array: ";
    for(auto x: out) {
        cout << x << " ";
    }
    return 0;
}

// TC -> O(n) 
// SC -> O(n) 