// Print any subsequence whose sum is k
#include<iostream>
#include<vector>
using namespace std;

bool printS(int ind, vector<int> &vec, int sum, int k, int arr[], int n) {
    if(ind >= n) {
        // condition satisfied
        if(k == sum) {
            for(auto it:vec)    cout << it << " ";
            cout << endl;
            return true;
        }
        // condition not satisfied
        else    return false;
    }
    //picking the current element
    vec.push_back(arr[ind]);
    sum += arr[ind];
    if(printS(ind+1, vec, sum, k, arr, n))  return true;

    // not picking the current element
    sum -= arr[ind];
    vec.pop_back();
    if(printS(ind+1, vec, sum, k, arr, n))  return true;

    return false;
}

int main() {
    int n;
    cout << "Enter array size: ";
    cin >> n;

    int* arr = new int[n];
    cout << "Enter array: \n";
    for(int i=0;i<n;i++) {
        int tmp;
        cin >> tmp;
        arr[i] = tmp;
    }

    int k;
    cout << "Enter Sum: ";
    cin >> k;

    vector<int> vec;
    printS(0, vec, 0, k, arr, n);

    return 0;
}