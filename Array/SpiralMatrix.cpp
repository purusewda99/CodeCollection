// Print the matrix in a spiral form
#include<iostream>
#include<vector>
using namespace std;

void printSpiralMatrix(vector<vector<int>> matrix) {
    int endpointx1 = 0, endpointx2 = matrix.size()-1;
    int endpointy1 = 0, endpointy2 = matrix[0].size()-1;

    while(endpointx1<(endpointx2+1) && endpointy1<(endpointy2+1)) {
        // first row from the remaining rows
        for(int i=endpointy1; i<=endpointy2; i++) {
            cout << matrix[endpointx1][i] << " ";
        }
        endpointx1++;

        // last column from the remaining columns
        for(int i=endpointx1; i<=endpointx2; i++) {
            cout << matrix[i][endpointy2] << " ";
        }
        endpointy2--;

        // last row from the remaining rows
        if(endpointx1<(endpointx2+1)) {
            for(int i=endpointy2; i>=endpointy1; i--) {
                cout << matrix[endpointx2][i] << " ";
            }
            endpointx2--;
        }

        // first column from the remaining columns 
        if(endpointy1<(endpointy2+1)) {
            for(int i=endpointx2; i>=endpointx1; i--) {
                cout << matrix[i][endpointy1] << " ";
            }
            endpointy1++;
        }
    }

    return ;
}

int main() {
    int row_siz, col_siz;
    cout << "Enter row size: ";
    cin >> row_siz;
    cout << "Enter column size: ";
    cin >> col_siz;

    vector<vector<int>> matrix(row_siz, vector<int> (col_siz));
    for(int i=0; i<row_siz; i++) {
        cout << "Enter the matrix's " << i << "th row: ";
        for(int j=0; j<col_siz; j++) {
            int tmp;
            cin >> tmp;
            matrix[i][j] = tmp;
        }
    }

    printSpiralMatrix(matrix);
    return 0;
}