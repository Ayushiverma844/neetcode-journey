class Solution {
public:
vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    int srow = 0, erow = m - 1;
    int scol = 0, ecol = n - 1;
    vector<int> ans;

    while (srow <= erow && scol <= ecol) {
        // Top row: Traverse from left to right
        for (int j = scol; j <= ecol; j++) {
            ans.push_back(matrix[srow][j]);
        }
        srow++; // Move down to the next row

        // Right column: Traverse from top to bottom
        if (scol <= ecol) {
            for (int i = srow; i <= erow; i++) {
                ans.push_back(matrix[i][ecol]);
            }
            ecol--; // Move left to the previous column
        }

        // Bottom row: Traverse from right to left
        if (srow <= erow) {
            for (int j = ecol; j >= scol; j--) {
                ans.push_back(matrix[erow][j]);
            }
            erow--; // Move up to the previous row
        }

        // Left column: Traverse from bottom to top
        if (scol <= ecol) {
            for (int i = erow; i >= srow; i--) {
                ans.push_back(matrix[i][scol]);
            }
            scol++; // Move right to the next column
        }
    }

    return ans;
}

};