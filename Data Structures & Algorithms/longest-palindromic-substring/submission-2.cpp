class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();

        if(n <= 1) return s;
        vector<vector<int>> dp(n, vector<int> (n, 0));

        int maxlen = 0;
        string ans = "";

        for(int i = 0; i < n; i++){
            dp[i][i] = 1;
            if(dp[i][i] && 1 > maxlen){
                maxlen = 1;
                ans = s.substr(i, 1);
            }
        }
        for(int i = 0; i < n-1; i++){
            dp[i][i+1] = (s[i] == s[i+1]) ? 1 : 0;
            if(dp[i][i+1] && 2 > maxlen){
                maxlen = 2;
                ans = s.substr(i, 2);
            }
        }

        for(int i = 2; i < n; i++){
            for(int j = 0; j < n-i; j++){
                // dp[j][j+i]

                if(s[j] == s[j+i] && dp[j+1][j+i-1] == 1){
                    dp[j][j+i] = 1;

                }

                if(dp[j][j+i] && (i+1) > maxlen){
                    maxlen = i+1;
                    ans = s.substr(j, i+1);
                }
            }
        }
        return ans;
    }
};
