class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        if(nums.size() == 0){
            return 0;
        }
        int ans =1;
        int count = 1;
        for(int i=1;i<nums.size();i++){
          
           // Ignore duplicate elements
          if(nums[i] == nums[i-1]){
            continue;
          }
           // Check consecutive numbers
          else if(nums[i] == nums[i-1]+1){
            count++ ;
          }
          // reset if sequence breaks
          else{
            count =1;
          }
          ans = max(ans,count);

        }
        return ans;
    }
};
