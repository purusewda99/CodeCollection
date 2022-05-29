#include<iostream>
#include<vector>
using namespace std;

void printSubsequences(int arr[], int index, vector<int> &subarr, int n) {
    if(index >= n) {
        for(auto it : subarr) {
            cout << it << " ";
        }
        if(subarr.size() == 0)  cout << "{}";
        cout << endl;
        return;
    }
    else {
        subarr.push_back(arr[index]);
        printSubsequences(arr, index+1, subarr, n);
        subarr.pop_back();
        printSubsequences(arr, index+1, subarr, n);
    }
}

int main() {
    int n;
    cout << "Enter array size: ";
    cin >> n;
    int* arr = new int[n];
    cout << "Enter array: ";
    for(int i=0;i<n;i++) {
        int tmp;
        cin >> tmp;
        arr[i] = tmp;
    }
    vector<int> vec;
      
 
    printSubsequences(arr, 0, vec,n);
 
    return 0;
}