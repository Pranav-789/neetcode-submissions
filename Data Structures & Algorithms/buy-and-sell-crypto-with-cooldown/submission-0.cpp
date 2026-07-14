class Solution {
    int func(vector<int>& prices, int idx, bool holding,vector<vector<int>>& dp){
        if(idx >= prices.size()){
            return 0;
        }

        if(dp[idx][holding] != -1){
            return dp[idx][holding];
        }
        
        if(!holding){
            return dp[idx][holding] =  max(
                func(prices, idx+1, false, dp),
                -prices[idx] + func(prices, idx+1, true, dp)
            );
        }else{
            return dp[idx][holding] =  max(
                func(prices, idx + 1, true, dp),
                prices[idx] + func(prices, idx+2, false, dp)
            );
        }
    }
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(), vector<int>(2, -1));
        return func(prices, 0, false, dp);
    }
};
