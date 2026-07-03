class Solution {
public:
    int change(int amount, vector<int>& coins) {
    //         1   2   3   4
    //    1    1   1   1   1
    //    2    1   2   2   3
    //    3    1   2   3   4

       int n = coins.size();

        vector<int> prev(amount+1, 0);

        if(coins.empty()) return amount == 0;
        if(amount == 0) return 1;

        prev[0] = 1;

        for(int i = coins[0]; i <= amount; i++){
            if(prev[i-coins[0]]){
                prev[i] = prev[i-coins[0]];
            }
        }

        for(int i = 1; i < n; i++){
            vector<int> curr(amount+1, 0);
            for(int j = 0; j < coins[i]; j++){
                curr[j] = prev[j];
            }

            for(int j = coins[i]; j <= amount; j++){
                curr[j] = curr[j-coins[i]] +prev[j];
            }
            prev = curr;
        }

        return prev[amount];
    }
};
