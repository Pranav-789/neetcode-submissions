class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int maxlen = 1;
        string ans = "";
        ans += s[0];
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                bool flag = true;
                int l = i, r = j;

                while(l <= r){
                    if(s[l] != s[r]){
                        flag = false;
                        break;
                    }
                    l++; r--;
                }
                if(flag && (j - i + 1 > maxlen)){
                    maxlen = j - i + 1;
                    ans = s.substr(i, maxlen);
                }
            }
        }
        return ans;
    }
};
