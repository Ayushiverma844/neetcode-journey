class Solution {
public:
    int uniquePaths(int m, int n) {
        // Create DP table of size m x n
        vector<vector<int>> dp(m,vector<int>(n));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){

                // Starting cell has only 1 way
                if(i==0 && j==0){
                    dp[i][j] = 1;
                }
                else{
                    // First column
                    // We can only come from the top
                    if(j-1 < 0 && i-1 >= 0){
                        dp[i][j]  = dp[i-1][j];
                    }
                    // First row
                    // We can only come from the left
                    else if(i-1 <0 && j-1 >=0){
                        dp[i][j] = dp[i][j-1];
                    }
                    // For all other cells
                    // Total paths = Top paths + Left paths
                    else{
                        dp[i][j] = dp[i-1][j] + dp[i][j-1];
                    }
                }
            }
        }
     // Answer is stored in the last cell
      return dp[m-1][n-1];
    }
};
