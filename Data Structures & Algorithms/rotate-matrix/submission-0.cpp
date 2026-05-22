class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {

        int row = matrix.size();
        int col = matrix[0].size();
        
        // reverse matrix , 1row <-> last row ans so on ..
        for(int i=0;i<row/2 ; i++){
            for(int j = 0 ; j <col ;j++){
                swap(matrix[i][j] , matrix[row-i-1][j]);
            }
        }

        // now perfom transposition of matrix ->means row to column , column to row
        for(int i=0;i<row;i++){
            for(int j = i;j<col ; j++){
                swap(matrix[i][j] , matrix[j][i]);
            }
        }
    }
};
