/*The n-queens puzzle is the problem of placing n queens on an n x n chessboard
such that no two queens attack each other.*/
#include <iostream>
#include <vector>
using namespace std;

void solve(int col, vector<string> &board, vector<vector<string>> &ans, vector<int> &leftRow,
           vector<int> &upperDiagonal, vector<int> &lowerDiagonal, int n)
{
    if (col == n)
    {
        ans.push_back(board);
        return;
    }

    for (int row = 0; row < n; row++)
    {
        if(leftRow[row] == 0 && lowerDiagonal[row+col] == 0 && upperDiagonal[n-1+col-row] == 0) 
        {
            board[row][col] = 'Q';
            leftRow[row] = 1;
            lowerDiagonal[row+col] = 1;
            upperDiagonal[n-1+col-row] = 1;

            solve(col+1, board, ans, leftRow, upperDiagonal, lowerDiagonal, n);

            board[row][col] = '.';
            leftRow[row] = 0;
            lowerDiagonal[row+col] = 0;
            upperDiagonal[n-1+col-row] = 0;
        }
    }
}

vector<vector<string>> solveNQueens(int n)
{
    vector<vector<string>> ans;
    vector<string> board(n);
    string s(n, '.');
    for (int i = 0; i < n; i++)
        board[i] = s;
    vector<int> leftRow(n, 0), upperDiagonal((2 * n) - 1, 0), lowerDiagonal((2 * n) - 1, 0);
    solve(0, board, ans, leftRow, upperDiagonal, lowerDiagonal, n);
    return ans;
}

int main()
{
    int n;
    cout << "Enter chessboard size: ";
    cin >> n;
    vector<vector<string>> out = solveNQueens(n);
    for (int i = 0; i < out.size(); i++)
    {
        for (int j = 0; j < out[i].size(); j++)
        {
            cout << out[i][j] << " ";
        }
        cout << endl << endl;
    }
}