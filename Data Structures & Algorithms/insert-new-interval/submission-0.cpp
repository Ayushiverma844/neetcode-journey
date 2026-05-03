class Solution {
public:
    vector<vector<int>> mergeOverlap(vector<vector<int>>& temp){
          vector<vector<int>> ans;
          for(int i=0;i<temp.size();i++){
            if(ans.empty() || ans.back()[1] < temp[i][0]){
                // / no overlap
                ans.push_back(temp[i]);
            }
            else{
                //overlap
                ans.back()[1] = max(ans.back()[1] , temp[i][1] );
            }
          }
          return ans;
    }
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
          vector<vector<int>> temp;
         // Step 1: Add all intervals
        for(int i = 0; i < intervals.size(); i++){
            temp.push_back(intervals[i]);
        }

        // Step 2: Add new interval
        temp.push_back(newInterval);

        // Step 3: Sort intervals
        sort(temp.begin(), temp.end());
        
             // Step 4: Merge
        vector<vector<int>> ans = mergeOverlap(temp);

        return ans; 
        

    }
};
