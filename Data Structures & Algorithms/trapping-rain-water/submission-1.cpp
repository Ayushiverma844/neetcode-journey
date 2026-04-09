class Solution {
public:
    int trap(vector<int>& h) {
        int ans = 0;
        int n = h.size() ;
        int leftMax = 0 , rightMax = 0;
        int l = 0 , r = n-1;

        while(l<r){
            leftMax = max(h[l],leftMax);
            rightMax = max(h[r],rightMax);

            if(leftMax < rightMax){
                ans += (leftMax-h[l]);
                l++;
            }
            else{
                ans += (rightMax-h[r]);
                r--;
            }
        }
        return ans;
    }
};
