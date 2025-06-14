class Solution {
public:
    long long maximumProfit(vector<int>& prices, int k) {
        int n = prices.size();
        
        if (n < 2 || k == 0) return 0;

        vector<vector<long long>> dp(k + 1, vector<long long>(3, 0));

        for (int t = 0; t <= k; ++t) {
            
            dp[t][1] = dp[t][2] = INT_MIN;
        }

        for (int price : prices) {
            for (int t = k; t >= 1; --t) {
                
                dp[t][0] = max(dp[t][0], dp[t][1] + price);
                dp[t][0] = max(dp[t][0], dp[t][2] - price);

                dp[t][1] = max(dp[t][1], dp[t - 1][0] - price);
                dp[t][2] = max(dp[t][2], dp[t - 1][0] + price);
            }
        }

        return dp[k][0];
        
    }
};©leetcode
