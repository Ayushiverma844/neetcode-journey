class Solution {
public:
    int dfs(vector<int>& nums , int i , vector<int>& temp){
        if(i >= nums.size()){
            return 0;
        }
        if(temp[i] != -1){
            return temp[i];
        }
        temp[i] = max(dfs(nums,i+1,temp) , nums[i]+dfs(nums,i+2,temp));
        return temp[i];
    }
    int rob(vector<int>& nums) {
        vector<int> temp(nums.size(),-1);
        return dfs(nums,0,temp);
    }
};
