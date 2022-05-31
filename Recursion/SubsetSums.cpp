// print sums of all subsets in it.
#include <iostream>
#include <vector>
using namespace std;

// Alternative approach
// void func(int ind, int sum, vector<int>& arr, int N, vector<int> sumSubset) {
//     if(ind == N)
//     {
//         sumSubset.push_back(sum);
//         return;
//     }
//     // pick the element
//     func(ind+1, sum + arr[ind], arr, N, sumSubset);
//     // do not pick the element
//     func(ind+1, sum, arr, N, sumSubset);
// }

void subsets(vector<int> &arr, int N, int sum, int ind, vector<int> &sums)
{
    if (ind >= N)   return;

    for (int i = ind; i < N; i++)
    {
        sum += arr[i];
        sums.push_back(sum);
        subsets(arr, N, sum, i + 1, sums);
        sum -= arr[i];
    }
}

vector<int> subsetSums(vector<int> arr, int N)
{
    vector<int> sums;
    sums.push_back(0);
    subsets(arr, N, 0, 0, sums);
    return sums;
}

int main()
{
    int n;
    cout << "Enter array size: ";
    cin >> n;
    vector<int> arr;
    cout << "Enter array: ";
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        arr.push_back(tmp);
    }
    vector<int> out = subsetSums(arr, n);
    for (int i = 0; i < out.size(); i++)
    {
        cout << out[i] << " ";
    }

    return 0;
}

// time complexity -> O(2^n)
//                 -> O((2^n) +(2^nlog(2^n))(only if sorting the output)) 
// space complexity -> O(2^n)