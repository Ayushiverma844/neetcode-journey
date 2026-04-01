class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> m;

        for(int i=0;i<nums.size();i++){
            int opp = target - nums[i];
            if(m.find(opp) != m.end()){
                //found
                return {m[opp] , i};
            }
            m[nums[i]] = i;
        }
        return {} ;
    }
};
