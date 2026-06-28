class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, int> mp;

        for(auto x: nums){
            if(!mp[x]) mp[x] = 0;
            mp[x]++;

            if(mp[x] >= 2) return true;
        }

        return false;
    }
};