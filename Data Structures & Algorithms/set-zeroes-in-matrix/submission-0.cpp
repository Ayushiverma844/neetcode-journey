class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        // To mark zero positions
        vector<pair<int,int>> zeroes ;

        // Step 1: Store positions of 0
        for(int i=0;i< m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j] == 0){
                    zeroes.push_back({i,j});
                }
            }
        }
        
        // Step 2: Set row and column to 0 for all stored positions
        for(auto &pos : zeroes){
            int row = pos.first;
            int col = pos.second;
            
            // Set entire row to 0
            for(int j = 0 ; j< n ; j++){
                matrix[row][j] = 0;
            }
            // Set entire column to 0
            for(int i=0;i< m;i++){
                matrix[i][col] = 0;
            }
             
        }
    }
};
