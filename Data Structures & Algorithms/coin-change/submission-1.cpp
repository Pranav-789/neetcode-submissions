class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, 1e9));

        dp[0][0] = 0;
        if(coins[0] <= amount)dp[0][coins[0]] = 1;
        for(int i = coins[0]+1; i <= amount; i++){
            dp[0][i] = min(1 + dp[0][i-coins[0]], dp[0][i]);
        }

        for(int i = 1; i < n; i++){
            for(int j = 0; j <= amount; j++){
                if(j < coins[i]){
                    dp[i][j] = dp[i-1][j];
                }else{
                    dp[i][j] = min(1+dp[i][j-coins[i]], dp[i-1][j]);
                }
            }
        }
        return dp[n-1][amount] == 1e9 ? -1 : dp[n-1][amount];
    }
};
