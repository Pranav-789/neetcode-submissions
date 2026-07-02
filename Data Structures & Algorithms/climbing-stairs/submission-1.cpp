class Solution {
    // a recursion approacha
    // int steps(int n){
    //     if(n == 0) return 1;
    //     if(n < 0) return 0;

    //     return steps(n-1) + steps(n-2);
    // }
    

    // aproach 2: memoization
    // int steps(int n, vector<int>& dp){
    //     if(n == 0) return 1;
    //     if(n < 0) return 0;
    //     if(dp[n] != -1) return dp[n];

    //     return dp[n] = steps(n-1, dp) + steps(n-2, dp);
    // }
public:
    int climbStairs(int n) {
        if(n <= 1) return n;
        vector<int> dp(n+1, -1);
        dp[0] = 1;
        dp[1] = 1;
        for(int i = 2; i <= n; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};
