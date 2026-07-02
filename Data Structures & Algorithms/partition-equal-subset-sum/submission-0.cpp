class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        for(auto it: nums) sum += it;

        vector<vector<bool>> dp(n, vector<bool> (sum+1, 0));

        dp[0][0] = 1;
        dp[0][nums[0]] = 1;

        for(int i = 1; i < n; i++){
            for(int j = 0; j <= sum; j++){
                if(dp[i-1][j]){
                    dp[i][j] = 1;
                    dp[i][j+nums[i]] = 1;
                }
                if(j != 0 && dp[i][j] && (sum - j == j)) return true;
            }
        }
        return false;
    }
};
