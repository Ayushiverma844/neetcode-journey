class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> right(n,0) ; // store index of next smaller element on right
        vector<int> left(n,0); // store index of next smaller element on left
        stack<int> s ; //stack stores indices (used later for width calculation)
 
        // Find next smaller element on right for each bar
        for(int i=n-1; i >=0;i--){
           while(s.size() > 0 && heights[s.top()] >= heights[i]){
               // pop until we find a smaller element
              s.pop();
           }
           right[i] = s.empty() ? n : s.top(); // if none found, use n
           s.push(i);
        }
         // Clear stack to reuse for left calculation
         while(s.size() > 0){
            s.pop();
         }

        // Find next smaller element on left for each bar
           for(int i=0; i < n;i++){
           while(s.size() > 0 && heights[s.top()] >= heights[i]){
              // pop until we find a smaller element
              s.pop();
           }
           left[i] = s.empty() ? -1 : s.top(); // if none found, use -1
           s.push(i);
        }

        // now calculate area;
        int ans = 0;
        for(int i=0;i<n;i++){
            int width = right[i]-left[i]-1;
            int currArea = heights[i] * width ; // area with current height
            ans = max(ans,currArea);
        }
      return ans;
    }
};
