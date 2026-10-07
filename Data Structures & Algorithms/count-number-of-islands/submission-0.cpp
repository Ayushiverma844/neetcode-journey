class Solution {
public:
  void dfs(vector<vector<char>>& grid ,int i,int j,vector<vector<bool>>&vis){
        int n = grid.size() ;
        int m = grid[0].size();

        if(i < 0 || j < 0 || i>= n || j >= m || vis[i][j] || grid[i][j] == '0'){
            return;
        }

        vis[i][j] = true ;

        //top
        dfs(grid,i-1,j,vis);
        //left
        dfs(grid,i,j-1,vis);
        //down
        dfs(grid,i+1,j,vis);
        //right
        dfs(grid,i,j+1,vis);
        
   }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size() ;
        int m = grid[0].size();
        int island = 0;
        vector<vector<bool>> vis(n,vector<bool>(m,false));

        for(int i=0;i<n;i++){
            for(int j = 0 ; j<m;j++){
                if(grid[i][j] == '1' && !vis[i][j]){
                    dfs(grid , i,j,vis);
                    island++ ;
                }
            }
        }
        return island ;
        
    }
};
