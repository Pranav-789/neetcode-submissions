class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int l = 0, r = 1;
        int profit = 0;
        while(r < n){
            if(prices[r] > prices[l]) profit = max(profit, prices[r]-prices[l]);

            if(prices[l] > prices[r]) l = r;
            r++;
        }
        return profit;
    }
};
