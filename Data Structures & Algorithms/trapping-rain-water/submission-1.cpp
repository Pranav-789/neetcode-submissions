class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> pref(n, 0);
        vector<int> suff(n, 0);

        for(int i = 1; i < n; i++) pref[i] = max(pref[i-1], height[i-1]);

        for(int i = n-2; i >= 0; i--) suff[i] = max(suff[i+1], height[i+1]);

        int ans = 0;
        for(int i = 0; i < n; i++){
            ans += max(min(pref[i], suff[i]) - height[i], 0);
        }
        return ans;
    }
};
