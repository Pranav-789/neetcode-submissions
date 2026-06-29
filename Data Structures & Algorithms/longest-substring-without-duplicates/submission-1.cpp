class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0, n = s.size();
        set<char> seen;
        int maxlen = 0;
        if(n <= 1) return n;
        for(int r = 0; r < n; r++){
            while(seen.count(s[r]) != 0){
                seen.erase(s[l]);
                l++;
            }
            seen.insert(s[r]);
            maxlen = max(maxlen, r-l+1);
        }
        return maxlen;
    }
};
