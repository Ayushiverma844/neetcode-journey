class Solution {
public:
    
    // bst on row
    bool bst(vector<vector<int>>& matrix,int target , int row){
        int n = matrix[0].size();
        int st = 0 , end = n-1;
        while(st <= end){
            int mid = st + (end-st)/2;
            if(target == matrix[row][mid]){
                return true;
            }
            else if(target > matrix[row][mid]){
                //right
                st = mid+1;
            }
            else{
                //left
                end = mid-1;
            }
        }
        return false;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(); // number of rows
        int n = matrix[0].size(); // number of columns

        int stRow = 0 , endRow = m-1;

        // first find in which row the number can ouccur then apply bst on that row to find number

        while(stRow <= endRow){
            int mid = stRow+(endRow-stRow) /2;

            if(target >= matrix[mid][0] && target <= matrix[mid][n-1] ){
                // target will appear this this row , 
                return bst(matrix,target,mid);
            }
            else if(target < matrix[mid][0]){
                // find upwards
                endRow = mid-1;
            }
            else{
                //find downwards
                stRow = mid+1;
            }
        }
        //if not found
        return false;
    }
};
