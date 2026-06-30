class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int ans = 0;
        for(char c = 'A'; c <= 'Z'; c++){
            for(int i = 0; i < n; i++){
                int t = k;
                for(int j = i; j < n; j++){
                    if(s[j] != c) t--;
                    if(t < 0) break;
                    ans = max(ans, j-i+1);
                }
            }
        }
        return ans;
    }
};