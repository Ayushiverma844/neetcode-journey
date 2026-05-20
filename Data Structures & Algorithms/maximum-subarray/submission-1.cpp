class Solution {
public:
    int maxSubArray(vector<int>& nums) {

      // Kadane’s Algorithm.
      int ans = INT_MIN , currSum = 0;
      for(int i=0;i<nums.size();i++){
       
        if(currSum < 0){
           currSum = 0;
        }
         currSum += nums[i];
        ans = max(ans,currSum);
      }
      return ans;
    }
};
