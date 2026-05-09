class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        int n = nums.size();

        for(int i=0; i+k <= n;i++){
             int maxi = nums[i];
            for(int j=i;j<i+k ;j++){
                 maxi = max(nums[j],maxi);

            }
            ans.push_back(maxi);
        }      
        return ans;
    }
};
