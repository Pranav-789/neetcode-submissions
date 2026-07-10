class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxP = -1e9;
        int suff = 1;
        int pref = 1;
        int n = nums.size();

        for(int i = 0; i < n; i++){
            suff = (suff == 0) ? nums[n-i-1] : suff*nums[n-i-1];
            pref = (pref == 0) ? nums[i] : pref*nums[i];

            maxP = max(maxP, max(suff, pref));
        }
        return maxP;
    }
};