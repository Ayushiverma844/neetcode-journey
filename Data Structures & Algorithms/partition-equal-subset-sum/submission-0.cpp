class Solution {
public:
    int sum(vector<int>& nums){
        int s = 0;
        for(int i=0;i<nums.size();i++){
            s += nums[i];
        }
        return s;
    }

    bool canPartition(vector<int>& nums) {
       int total = sum(nums);

    // if total sum is odd , it is impossible to devide array in 2 parts of equal  sum
     if(total % 2 != 0){
        return false;
     }     

     int target = total / 2;
     vector<bool> dp(target+1 , false);

     dp[0] = true;

     for(int i=0;i<nums.size();i++){
        for(int j= target; j>=nums[i] ; j--){
            dp[j] = dp[j] || dp[j-nums[i]];
        }
     }

     return dp[target];
    }
};
