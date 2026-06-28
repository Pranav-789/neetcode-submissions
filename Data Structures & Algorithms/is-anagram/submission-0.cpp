class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> chars(26, 0);

        for(int i = 0; i < s.size(); i++){
            chars[s[i]-'a']++;
        }

        for(int i = 0; i < t.size(); i++){
            chars[t[i]-'a']--;
        }

        for(int i = 0; i < 26; i++) if(chars[i] != 0) return false;
        return true;
    }
};
