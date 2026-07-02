class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int cnt = 0;
        sort(coins.begin(), coins.end());

        for(int i = coins.size()-1; i >= 0 && amount > 0; i--){
            int sub = amount/coins[i];
            cnt += sub;
            amount -= (sub*coins[i]);
        }
        return (amount > 0)? -1: cnt;
    }
};
