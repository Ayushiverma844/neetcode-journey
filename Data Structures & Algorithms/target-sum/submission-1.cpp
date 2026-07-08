class Solution {
public:
// aproach 2 -> dp
    
    int findTargetSumWays(vector<int>& nums, int target) {
        unordered_map<int , int> dp;
        dp[0] = 1;

        for(int i : nums){
            unordered_map<int , int> nextdp ;
            for(auto& entry :dp){
                int total = entry.first;
                int count = entry.second ;
                nextdp[total+ i] += count ;
                nextdp[total-i] += count ;
            }
            dp = nextdp;
        }
        return dp[target];
    }
};
