class Solution {
    bool check(char a, char b){
        int num = (a-'0')*10 + (b-'0');

        return (num >= 10 && num <= 26);
    }
public:
    int numDecodings(string s) {
        int n = s.size();
        if(n == 1) return s[0] != '0';
        if(s[0] == '0') return 0;

        vector<int> dp(n, 0);
        dp[0] = 1;
        dp[1] = 0;

        if(s[1] != '0') dp[1] += dp[0];

        if(check(s[0], s[1])) dp[1] += 1;

        for(int i = 2; i < n; i++){
            if(s[i] != '0')
                dp[i] += dp[i-1];

            if(check(s[i-1], s[i]))
                dp[i] += dp[i-2];
        }

        return dp[n-1];
    }
};


// 1012
// "1" -> one way to decode it

// "10" -> "1" & "0" or "10"
//          dp[i-1]  +  dp[i-2]

// x & y is there
// current is y, if i pick y seperately then number of ways => dp[i-1]
// if xy will form a valid number then dp[i-2]
// sum both