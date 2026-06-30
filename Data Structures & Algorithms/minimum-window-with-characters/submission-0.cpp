class Solution {
    bool cmp(vector<int>& v1, vector<int>& v2){
        for(int i = 0; i < 58; i++){
            if(v1[i] > 0){
                if(v2[i] < v1[i]) return false;
            }
        }
        return true;
    }
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();

        int l = 0;
        vector<int> v1(58, 0);

        vector<int> v2(58, 0);

        for(auto it: t){
            v1[it-'A']++;
        }

        string ans = "";
        for(int r = 0; r < n; r++){
            v2[s[r]-'A']++;

            while(cmp(v1, v2)){
                if(ans == "" || ans.size() > r-l+1){
                    ans = s.substr(l, r-l+1);
                }
                v2[s[l]-'A']--;
                l++;
            }
        }
        return ans;
    }
};