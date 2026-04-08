class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int best_Buy = prices[0];
        for(int i=1;i<prices.size();i++){
            if(prices[i] < best_Buy){
                best_Buy = prices[i];
            }
            ans = max(ans,prices[i]-best_Buy);
        }
        return ans;
   }
};
