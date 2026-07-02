class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, 1e9));
        vector<int> prev(amount+1, 1e9);

        prev[0] = 0;
        if(coins[0] <= amount) prev[coins[0]] = 1;
        for(int i = coins[0]+1; i <= amount; i++){
            prev[i] = min(1 + prev[i-coins[0]], prev[i]);
        }

        for(int i = 1; i < n; i++){
            vector<int> curr(amount+1, 1e9);
            for(int j = 0; j <= amount; j++){
                if(j < coins[i]){
                    curr[j] = prev[j];
                }else{
                    curr[j] = min(1+curr[j-coins[i]], prev[j]);
                }
            }
            prev = curr;
        }
        return prev[amount] == 1e9 ? -1 : prev[amount];
    }
};
