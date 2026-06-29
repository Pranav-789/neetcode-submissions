class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> suffMax(n, 0);

        for(int i = n-2; i >= 0; i--){
            suffMax[i] = max(suffMax[i+1], prices[i+1]);
        }
        int profit = 0;
        for(int i = 0; i < n; i++){
            profit = max(profit, suffMax[i]-prices[i]);
        }
        return profit;
    }
};
