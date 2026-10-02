class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n <= 1) return 0;
        
        vector<int> buy(n,0);
        vector<int> sell(n,0);
        vector<int> cooldown (n,0);

        buy[0] = -prices[0] ; //buy

        for(int i=1; i < n ; i++){
            // Holding a coin
            buy[i] = max(buy[i-1] , cooldown[i-1]-prices[i]);
            // Selling today
            sell[i] = buy[i-1] + prices[i] ;
            // Not holding and not selling today
            cooldown[i] = max(cooldown[i-1] , sell[i-1]);
        }
        return max(cooldown[n-1] , sell[n-1]);
    }
};
