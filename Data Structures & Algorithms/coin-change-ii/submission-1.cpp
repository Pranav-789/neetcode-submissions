class Solution {
public:
    int change(int amount, vector<int>& coins) {
    //         1   2   3   4
    //    1    1   1   1   1
    //    2    1   2   2   3
    //    3    1   2   3   4

       int n = coins.size();

        vector<vector<int>> dp(n, vector<int> (amount+1, 0));

        if(amount == 0) return 1;

        for(int i = 0; i < n; i++){
            dp[i][0] = 1;
        }

        for(int i = coins[0]; i <= amount; i++){
            if(dp[0][i-coins[0]]){
                dp[0][i] = dp[0][i-coins[0]];
            }
        }

        for(int i = 1; i < n; i++){
            for(int j = 1; j < coins[i]; j++){
                dp[i][j] = dp[i-1][j];
            }

            for(int j = coins[i]; j <= amount; j++){
                dp[i][j] = dp[i][j-coins[i]] +dp[i-1][j];
            }
        }

        return dp[n-1][amount];
    }
};
