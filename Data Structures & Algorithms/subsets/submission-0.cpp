class Solution {
public:
    // Recursive function to generate all subsets
    void getAllSubsets(vector<int>& nums,vector<int>& ans,int i , vector<vector<int>>& allsubset){

        // Base Case:
        // If we have processed all elements
        if(i == nums.size()){
            allsubset.push_back(ans);
            return ;
        }
        
          // Choice 1: Include nums[i]
        ans.push_back(nums[i]);
        getAllSubsets(nums, ans, i + 1, allsubset);

        // Backtracking
        // Remove the last added element
        ans.pop_back(); 
         // Choice 2: Exclude nums[i]
        getAllSubsets(nums, ans, i + 1, allsubset);
    
    }


    vector<vector<int>> subsets(vector<int>& nums) {
         vector<vector<int>> allSubset ; // Stores all subsets
         vector<int> ans;               // Current subset
    
         getAllSubsets(nums,ans,0,allSubset);
     return allSubset ;   
    }
};
