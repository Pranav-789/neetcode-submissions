class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1, 0);

        for(int i = 0; i <= n; i++){
            int cnt = 0;
            for(int j = 0; j < 32; j++){
                if((i >> j)&1) cnt++;
            }
            ans[i] = cnt;
        }
        return ans;
    }
};
