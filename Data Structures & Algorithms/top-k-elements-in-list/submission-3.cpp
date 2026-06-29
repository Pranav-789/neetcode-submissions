class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;

        for(auto it: nums){
            mp[it]++;
        }

        vector<vector<int>> buckets(nums.size()+1);
        for(auto it: mp){
            buckets[it.second].push_back(it.first);
        }
        int cnt = 0;
        vector<int> ans;
        for(int i = nums.size(); i >= 0; i--){
            int j = 0;
            int m = buckets[i].size();
            while(cnt < k && j < m){
                ans.push_back(buckets[i][j]);
                j++;
                cnt++;
            }
            if(cnt > k) break;
        }
        return ans;
    }
};
