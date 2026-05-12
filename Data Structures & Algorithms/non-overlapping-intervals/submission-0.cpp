class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        // sort by starting time
        sort(intervals.begin(),intervals.end());

        int prevEnd  = intervals[0][1];
        int cnt = 0;

        for(int i=1;i<intervals.size();i++){
          if(prevEnd > intervals[i][0]){
            // overlap  -> need to remove this interval
            cnt++;
            // keep minimum end
            prevEnd = min(prevEnd , intervals[i][1]); 
          }
          else{
            prevEnd = intervals[i][1];
          }
        }
        return cnt;
    }
};
