class Solution {
    int maxSum;
    int rec(vector<int>& nums, int target, int idx, vector<vector<int>>& dp){
        if(idx == nums.size()){
            return target == 0;
        }

        if(target > maxSum || target < -maxSum)
            return 0;

        if(dp[target+maxSum][idx] != -1) return dp[target+maxSum][idx];

        int way2 = rec(nums, target-nums[idx], idx+1, dp);
        int way3 = rec(nums, target+nums[idx], idx+1, dp);

        return dp[target+maxSum][idx] = way2 + way3;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        maxSum = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++) maxSum += nums[i];

        vector<vector<int>> dp(2*maxSum + 1, vector<int>(n, -1));

        return rec(nums, target, 0, dp);
    }
};