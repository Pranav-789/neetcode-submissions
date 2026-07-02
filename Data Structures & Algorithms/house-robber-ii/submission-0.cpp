class Solution {
    int solve(vector<int>& nums, int s, int e){
        int n = nums.size();

        vector<int> dp(e-s+1, 0);
        dp[0] = nums[s];
        dp[1] = max(nums[s], nums[s+1]);


        for(int i = s+2; i <= e; i++){
            dp[i-s] = max(nums[i] + dp[i-s-2], dp[i-s-1]);
        }

        return dp[e-s];
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0], nums[1]);
        return max(solve(nums, 0, n-2), solve(nums, 1, n-1));
    }
};
