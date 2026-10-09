class Solution {
public:

    void dfs(vector<vector<int>>& grid , vector<vector<bool>>& vis , int i , int j , int &area){
        int n = grid.size();
        int m = grid[0].size();

        if( i < 0 || j < 0 || i >= n || j >= m || vis[i][j] || grid[i][j] == 0){
            return ;
        }

        vis[i][j] = true;
        area++;

        //top 
        dfs(grid , vis , i-1 , j , area);
        //left 
        dfs(grid , vis , i , j-1 , area);
        //down
        dfs(grid , vis , i+1 , j , area);
        //right 
        dfs(grid , vis , i , j+1 , area);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,false));

        for(int i=0;i<n;i++){
            for(int j =0;j<m;j++){
                int area = 0;
                if(grid[i][j] == 1 && !vis[i][j]){
                    dfs(grid , vis , i , j , area );
                    maxArea = max(maxArea,area) ;
                }
            }
        }
        return maxArea;
    }
};
