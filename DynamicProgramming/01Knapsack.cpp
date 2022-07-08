#include<iostream>
#include<vector>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of items: ";
    cin >> n;
    cout << "Enter weights: ";
    vector<int> wt(n);
    for(int i=0;i<n;i++) {
        int tmp;
        cin >> tmp;
        wt[i] = tmp;
    }
    cout << "Enter values: ";
    vector<int> val(n);
    for(int i=0;i<n;i++) {
        int tmp;
        cin >> tmp;
        val[i] = tmp;
    }
    cout << "Enter weight of bag: ";
    int W;
    cin >> W;

    vector<vector<int>> t(n+1, vector<int>(W+1, 0));
    for(int i=0;i<(n+1);i++) {
        for(int j=0;j<(W+1);j++) {
            if(i==0 || j==0)    
                t[i][j] = 0;
            else if(wt[i-1] <= j) 
                t[i][j] = max((val[i-1]+t[i-1][j-wt[i-1]]),t[i-1][j]);
            else 
                t[i][j] = t[i-1][j];
        }
    }

    cout << "Max. Profit: " << t[n][W];
}