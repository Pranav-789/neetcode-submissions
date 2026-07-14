class Solution {
    // int func(vector<int>& prices, int idx, bool holding,vector<vector<int>>& dp){
    //     if(idx >= prices.size()){
    //         return 0;
    //     }

    //     if(dp[idx][holding] != -1){
    //         return dp[idx][holding];
    //     }
        
    //     if(!holding){
    //         return dp[idx][holding] =  max(
    //             func(prices, idx+1, false, dp),
    //             -prices[idx] + func(prices, idx+1, true, dp)
    //         );
    //     }else{
    //         return dp[idx][holding] =  max(
    //             func(prices, idx + 1, true, dp),
    //             prices[idx] + func(prices, idx+2, false, dp)
    //         );
    //     }
    // }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+2, vector<int>(2, 0));

        for(int i = n-1; i >= 0; i--){
            for(int holding = 0; holding <= 1; holding++){
                if(holding == 1){
                    dp[i][1] = max(
                        dp[i+1][1], prices[i] + dp[i+2][0]
                    );
                }else{
                    dp[i][0] = max(
                        dp[i+1][0], -prices[i] + dp[i+1][1]
                    );
                }
            }
        }

        return dp[0][0];
    }
};
