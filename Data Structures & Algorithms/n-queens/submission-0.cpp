class Solution {
public:

    bool isSafe(vector<string>& board, int row, int col, int n) {

        // check column 
        for (int i = 0; i < row; i++) {
            if (board[i][col] == 'Q') {
                return false;
            }
        }

        // left upper diagonal (↖)
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }

        // right upper diagonal (↗)
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }

        return true;
    }

    void NQueen(vector<string>& board, int row, int n, vector<vector<string>>& ans) {

        // base case
        if (row == n) {
            ans.push_back(board);
            return;
        }

        for (int j = 0; j < n; j++) {
            if (isSafe(board, row, j, n)) {
                board[row][j] = 'Q';     // place queen
                NQueen(board, row + 1, n, ans);
                board[row][j] = '.';     // backtracking
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));
        NQueen(board, 0, n, ans);
        return ans;
    }
};