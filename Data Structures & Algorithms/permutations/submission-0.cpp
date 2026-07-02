class Solution {
public:
    void getAllpermutation(vector<int>& nums , vector<vector<int>>& ans , int idx){
        int n = nums.size();
        if(idx == n-1){
            ans.push_back({nums});
        }

        for(int i = idx ; i< n ;i++){
            swap(nums[i] , nums[idx]); //idx place <> ith element
            getAllpermutation(nums, ans , idx+1);
            swap(nums[i], nums[idx]) ; //backtracking
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        getAllpermutation(nums , ans , 0);
        return ans;
    }
};
