class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        if(n <= 1) return 0; // either way n >= 2 always

        // step k
        // prev = k - 1 || prev = k-2;

        // curr k -> min(cost to reach k-1 + cost[k-1], cost to reach k-2 + cost[k-2])
        // 1d dp
        
        vector<int> dp(n+1, 0);

        dp[0] = dp[1] = 0;

        for(int i = 2; i <= n; i++){
            dp[i] = min(dp[i-1] + cost[i-1], dp[i-2] + cost[i-2]);
        }

        return dp[n];
    }
};
