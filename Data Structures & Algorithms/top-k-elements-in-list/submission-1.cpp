class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;

        for(auto it: nums){
            mp[it]++;
        }

        priority_queue<pair<int, int>, vector<std::pair<int, int>>,greater<std::pair<int, int>>> pq;

        for(auto it: mp){
            pq.push({it.first, it.second});

            if(pq.size() > k)pq.pop();
        }

        vector<int> ans;
        while(!pq.empty()){
            auto it = pq.top();
            ans.push_back(it.first);
            pq.pop();
        }
        return ans;
    }
};
