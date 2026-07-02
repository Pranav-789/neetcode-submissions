class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        for(auto it: nums) sum += it;
        if(sum & 1) return false;
        int target = sum/2;

        vector<vector<bool>> dp(n, vector<bool> (target+1, 0));

        dp[0][0]= 1;
        if(nums[0] <= target) dp[0][nums[0]] = 1;
        
        for(int i = 1; i < n; i++){
            for(int j = 0; j <= target; j++){
                if(dp[i-1][j] == 1){
                    dp[i][j] = 1;
                    if(nums[i] + j <= target) dp[i][nums[i]+j] = 1;
                }
            }
        }
        
        return dp[n-1][target];
    }
};
