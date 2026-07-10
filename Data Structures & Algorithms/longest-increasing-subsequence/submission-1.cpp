class Solution {
    int func(int index, int prev_index, vector<int>& nums, vector<vector<int>>& dp){
        if(index >= nums.size()) return 0;

        if(dp[index][prev_index+1] != -1) return dp[index][prev_index+1];

        int len1 = (prev_index != -1 && nums[index] <= nums[prev_index]) ? 0 : 1 + func(index+1, index, nums, dp);
        int len2 = func(index+1, prev_index, nums, dp);

        return dp[index][prev_index+1] =max(len1, len2);
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n+1, -1));
        return func(0, -1, nums, dp);
    }
};