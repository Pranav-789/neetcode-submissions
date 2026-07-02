class Solution {
    // a recursion approacha
    // int steps(int n){
    //     if(n == 0) return 1;
    //     if(n < 0) return 0;

    //     return steps(n-1) + steps(n-2);
    // }
    
    int steps(int n, vector<int>& dp){
        if(n == 0) return 1;
        if(n < 0) return 0;
        if(dp[n] != -1) return dp[n];

        return dp[n] = steps(n-1, dp) + steps(n-2, dp);
    }
public:
    int climbStairs(int n) {
        vector<int> dp(n+1, -1);
        return steps(n, dp);
    }
};
