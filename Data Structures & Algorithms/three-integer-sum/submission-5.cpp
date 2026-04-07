class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        vector<vector<int>> ans;

        // Step 1: Sort array
        sort(nums.begin(), nums.end());

        // Fix first element
        for(int i = 0; i < nums.size() - 2; i++) {   

            // Skip duplicate first element
            if(i > 0 && nums[i] == nums[i-1]) {
                continue;
            }

            int j = i + 1;
            int k = nums.size() - 1;

            while(j < k) {

                int sum = nums[i] + nums[j] + nums[k];

                if(sum < 0) {
                    j++;
                }
                else if(sum > 0) {
                    k--;
                }
                else {

                    // Found triplet
                    ans.push_back({
                        nums[i],
                        nums[j],
                        nums[k]
                    });

                    j++;
                    k--;

                    // Skip duplicate left
                    while(j < k && nums[j] == nums[j-1]) {
                        j++;
                    }

                    // Skip duplicate right
                    while(j < k && nums[k] == nums[k+1]) {
                        k--;
                    }
                }
            }
        }

        return ans;
    }
};