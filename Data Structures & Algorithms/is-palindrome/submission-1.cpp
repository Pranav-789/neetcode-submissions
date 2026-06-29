class Solution {
    bool isalpha(char ch){
        return ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'));
    }

    bool isNum(char ch){
        return (ch >= '0' && ch <= '9');
    }


public:
    bool isPalindrome(string s) {
        int l = 0, r = s.size()-1;
        
        while(l < r){
            while(l < r && !(isalpha(s[l]) || isNum(s[l]))) l++;
            while(l < r && !(isalpha(s[r]) || isNum(s[r]))) r--;
            if(s[l] >= 'A' && s[l] <= 'Z') s[l] = s[l]-'A'+'a';
            if(s[r] >= 'A' && s[r] <= 'Z') s[r] = s[r]-'A'+'a';
            if(s[l] != s[r]) return false;
            l++;
            r--;
        }
        return true;
    }
};
