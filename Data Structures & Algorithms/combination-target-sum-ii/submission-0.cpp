class Solution {
public:
  void getAllCombination(vector<int>& arr, int idx,
                           vector<int>& comb,
                           vector<vector<int>>& ans,
                           int tar) {

        if (tar == 0) {
            ans.push_back(comb);
            return;
        }

        if (idx == arr.size() || tar < 0)
            return;

        //  TAKE current element
        comb.push_back(arr[idx]);
        getAllCombination(arr, idx + 1, comb, ans, tar - arr[idx]);
        comb.pop_back();

        //  SKIP duplicates before NOT TAKE
        int nextIdx = idx + 1;
        while (nextIdx < arr.size() && arr[nextIdx] == arr[idx]) {
            nextIdx++;
        }

        //  NOT TAKE (jump over duplicates)
        getAllCombination(arr, nextIdx, comb, ans, tar);
    }
    vector<vector<int>> combinationSum2(vector<int>& arr, int tar) {
        sort(arr.begin(),arr.end());
        vector<vector<int>> ans;
        vector<int> comb;
        getAllCombination(arr,0,comb,ans,tar);
        return ans;
    }
};