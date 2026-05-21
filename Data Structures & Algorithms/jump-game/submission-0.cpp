class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxReach = 0;

        for(int i=0;i<nums.size();i++){
            // Agar current index reachable nahi hai
            if(i > maxReach) {
                return false;
            }
            // update maximum reachable index
            maxReach = max(maxReach , nums[i]+i);

            //if we reach last index return true
            if(maxReach >= nums.size()-1){
                return true;
            }
        }
        return false;
    }
};
