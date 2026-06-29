class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;

        for(auto it: nums){
            mp[it]++;
        }

        priority_queue<pair<int, int>, vector<std::pair<int, int>>,greater<std::pair<int, int>>> pq;

        for(auto it: mp){
            pq.push({it.second, it.first});

            if(pq.size() > k)pq.pop();
        }

        vector<int> ans;
        while(!pq.empty()){
            auto it = pq.top();
            ans.push_back(it.second);
            pq.pop();
        }
        return ans;
    }
};
