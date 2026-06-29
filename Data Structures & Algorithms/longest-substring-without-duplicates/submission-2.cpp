class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0, n = s.size();
        vector<int> freq(256, 0);
        int maxlen = 0;
        if(n <= 1) return n;
        for(int r = 0; r < n; r++){
            freq[s[r]]++;
            while(freq[s[r]] > 1){
                freq[s[l]]--;
                l++;
            }
            maxlen = max(maxlen, r-l+1);
        }
        return maxlen;
    }
};
