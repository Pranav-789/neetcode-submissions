class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        for(auto it: nums) sum += it;
        if(sum & 1) return false;
        int target = sum/2;

        // vector<vector<bool>> dp(n, vector<bool> (target+1, 0));
        vector<bool> prev(target+1, 0);

        prev[0]= 1;
        if(nums[0] <= target) prev[nums[0]] = 1;
        
        for(int i = 1; i < n; i++){
            vector<bool> curr(target+1, 0);
            for(int j = 0; j <= target; j++){
                if(prev[j] == 1){
                    curr[j] = 1;
                    if(nums[i] + j <= target) curr[nums[i]+j] = 1;
                }
            }
            prev = curr;
        }
        
        return prev[target];
    }
};
