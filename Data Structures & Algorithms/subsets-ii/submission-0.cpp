class Solution {
public:
   void getAll(vector<int>& nums , vector<int>& sub , vector<vector<int>>& ans , int idx){
        int n = nums.size();
        
        //base case
        if(idx == n ){
            ans.push_back(sub);
            return ;
        }

         // Include current element
        sub.push_back(nums[idx]);

        getAll(nums , sub , ans ,idx+1 );
        
        // Exclude current element and skip duplicates
        sub.pop_back();
    
        int next = idx+1;
       
            while(next < n && nums[idx] == nums[next] ){
                next++ ;
            }
        
        getAll(nums,sub,ans,next);

   }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        vector<int> sub;
        getAll(nums,sub,ans,0);
        return ans;
    }
};
