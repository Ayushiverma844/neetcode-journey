class Solution {
public:
    // aproch1 -> recurssionn
    
     int solve(int i , int total , vector<int>& nums , int target){
        if( i == nums.size()){
            return total == target ;
        }
        return solve(i+1 , total+nums[i] , nums , target) + 
               solve(i+1 , total-nums[i] , nums , target) ;
     }
    int findTargetSumWays(vector<int>& nums, int target) {
        int ans = solve(0 , 0 , nums , target) ;
        return ans;
    }
};
