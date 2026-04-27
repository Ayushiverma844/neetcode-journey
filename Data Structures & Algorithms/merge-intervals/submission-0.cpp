class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
       vector<vector<int>> ans ;
       sort(intervals.begin(),intervals.end());
       int n = intervals.size();

       for(int i=0;i<n;i++){
        
        // no overlap
        if(ans.empty() || ans.back()[1] < intervals[i][0]){
          ans.push_back(intervals[i]);
        }
        else{
             // There is an overlap, merge the intervals
             ans.back()[1] = max(ans.back()[1], intervals[i][1]);
        }

       }  
       return ans;
    }
};
