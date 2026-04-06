class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        int i = 0, j = 1;

        // Loop until i reaches second last element
        while (i < nums.size() - 1) {

            // If j reaches end, move i forward
            if (j == nums.size()) {
                i++;          // move first pointer
                j = i + 1;    // reset second pointer
                continue;     // restart loop
            }

            // Check sum
            if (nums[i] + nums[j] == target) {
                return {i + 1, j + 1}; // returning indices
            }

            j++; // move second pointer
        }

        return {}; // if no pair found
    }
};