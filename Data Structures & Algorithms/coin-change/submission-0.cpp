class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {

        // If amount is 0, we don't need any coin.
        if (amount == 0) {
            return 0;
        }

        // dp[i] = minimum coins needed to make amount i.
        // Initialize every value with a large number (amount + 1),
        // which means "currently impossible".
        vector<int> dp(amount + 1, amount + 1);

        // Base case:
        // To make amount 0, we need 0 coins.
        dp[0] = 0;

        // Calculate answer for every amount from 1 to amount.
        for (int i = 1; i <= amount; i++) {

            // Try every coin.
            for (int coin : coins) {

                // We can use this coin only if it is not bigger than current amount.
                if (coin <= i) {

                    // Either keep old answer,
                    // or use this coin and add 1 to the answer of remaining amount.
                    dp[i] = min(dp[i], dp[i - coin] + 1);
                }
            }
        }

        // If dp[amount] is still a large value,
        // it means we cannot make this amount.
        if (dp[amount] > amount) {
            return -1;
        }

        // Otherwise return minimum coins needed.
        return dp[amount];
    }
};