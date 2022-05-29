// count the subsequences with sum = k
#include<iostream>
using namespace std;

int printS(int ind, int sum, int k, int arr[], int n) {
    if(sum > k) return 0;
    if(ind >= n) {
        // condition satisfied 
        if(sum == k)    return 1;
        // condition not satisfied
        else    return 0;
    }

    sum += arr[ind];
    int l = printS(ind+1, sum, k, arr, n);

    sum -= arr[ind];
    int r = printS(ind+1, sum, k, arr, n);

    return l+r;
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

    int k;
    cout << "Enter Sum: ";
    cin >> k;

    cout << printS(0, 0, k, arr, n);

    return 0;    
}
