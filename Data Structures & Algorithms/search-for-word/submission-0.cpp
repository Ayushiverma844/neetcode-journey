class Solution {
public:
    int m , n;
    vector<vector<int>> dir{{1,0},{0,1},{-1,0},{0,-1}};
    
    bool find(vector<vector<char>>& board,int i , int j , string word,int idx){
        if(idx == word.length()){
            //  BASE CASE: full word matched
            return true;
        }

        // boundary + visited check
        if (i < 0 || j < 0 || i >= m || j >= n || board[i][j] == 36) // 36 = ascii of $
            return false;
        
        // mismatch
        if (board[i][j] != word[idx])
            return false;
        
        char temp = board[i][j];
        board[i][j] = 36 ; // mark visited
        for (auto &d : dir) {
            int new_i = i + d[0];
            int new_j = j + d[1];

            if (find(board, new_i, new_j, word, idx + 1)) {
                board[i][j] = temp; // restore before return
                return true;
            }
        }

        board[i][j] = temp; // backtrack restore


        return false; 

    }
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n  = board[0].size();
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(find(board,i,j,word,0)){
                    return true;
                }
            }
        }
        return false;
    }
};
