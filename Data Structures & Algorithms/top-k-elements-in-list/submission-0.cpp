class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;

        for(auto it: nums){
            mp[it]++;
        }

        vector<pair<int, int>> p;
        for(auto it: mp) p.push_back({it.first, it.second});

        sort(p.begin(), p.end(), [](const pair<int, int>& a, const pair<int, int>& b){
            return a.second > b.second;
        });

        vector<int> ans;
        for(int i = 0; i < k; i++){
            ans.push_back(p[i].first);
        }

        return ans;
    }
};
