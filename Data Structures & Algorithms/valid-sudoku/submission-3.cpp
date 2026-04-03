class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        // Use sets to track digits
        vector<set<char>> rows(9);
        vector<set<char>> cols(9);
        vector<set<char>> grids(9);

        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){

                char val = board[i][j];

                // Skip empty cells
                if(val == '.')
                    continue;

                // Calculate grid index
                int gridIndex = (i / 3) * 3 + (j / 3);

                // Check duplicates
                if(rows[i].count(val) ||
                   cols[j].count(val) ||
                   grids[gridIndex].count(val))
                {
                    return false;
                }

                // Insert value
                rows[i].insert(val);
                cols[j].insert(val);
                grids[gridIndex].insert(val);
            }
        }

        return true;
    }
};