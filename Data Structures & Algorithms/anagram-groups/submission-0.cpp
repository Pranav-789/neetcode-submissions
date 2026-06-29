class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();

        vector<vector<string>> ans;
        vector<int> visited(n, 0);
        unordered_map<char, int> mp;

        for(int i = 0; i < n; i++){
            if(visited[i]) continue;
            mp.clear();
            for(auto ch: strs[i]){
                mp[ch]++;
            }
            vector<string> grp;
            grp.push_back(strs[i]);
            visited[i] = true;
            unordered_map<char, int> cmp;
            for(int j = i+1; j < n; j++){
                if(visited[j]) continue;
                cmp.clear();
                for(auto ch: strs[j]){
                    cmp[ch]++;
                }
                bool flag = true;
                for(auto it: mp){
                    if(cmp[it.first]!= it.second){
                        flag = false;
                        break;
                    }
                }
                if(flag){
                    visited[j] = 1;
                    grp.push_back(strs[j]);
                }
            }
            ans.push_back(grp);
        }
        return ans;
    }
};

