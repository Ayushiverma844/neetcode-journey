class Solution {
public:

    void getAllCombination(vector<int>& nums, int i,
                           vector<int>& combi,
                           vector<vector<int>>& ans,
                           int target) {

        // If target becomes 0, we found a valid combination
        if (target == 0) {
            ans.push_back(combi);
            return;
        }

        // If index goes out of range or target becomes negative, stop exploring
        if (target < 0 || i == nums.size()) {
            return;
        }

        // Choice 1: INCLUDE current element (we can reuse it again, so i stays same)
        combi.push_back(nums[i]);
        getAllCombination(nums, i, combi, ans, target - nums[i]);

        // Backtrack: remove last element before exploring next option
        combi.pop_back();

        // Choice 2: DO NOT include current element (move to next index)
        getAllCombination(nums, i + 1, combi, ans, target);
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end()); 

        vector<vector<int>> ans;
        vector<int> combi;

        getAllCombination(nums, 0, combi, ans, target);

        return ans;
    }
};