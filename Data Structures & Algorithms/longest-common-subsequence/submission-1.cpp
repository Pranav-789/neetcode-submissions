class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(), m = text2.size();

        vector<vector<int>> dp(n+1, vector<int> (m+1, 0));

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(text1[i-1] == text2[j-1]){
                    dp[i][j] = dp[i-1][j-1] + 1;
                }
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }

        return dp[n][m];
    }
};


//      c   r   a   b   t
//  c   1   1   1   1   1
//  a   1   1   2   2   2
//  t   1   1   2   2   3


//      a   b   c   d
//  a   1   1   1   1
//  b   1   2   2   2
//  c   1   2   3   3
//  d   1   2   3   4