class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> mp1(26, 0);
        for(auto it: s1){
            mp1[it-'a']++;
        }
        vector<int> mp2(26, 0);

        for(int r = 0; r < s2.size(); r++){
            mp2[s2[r]-'a']++;

            if(r >= s1.size()) mp2[s2[r-s1.size()]-'a']--;

            if(mp1 == mp2) return true;
        }
        return false;
    }
};
