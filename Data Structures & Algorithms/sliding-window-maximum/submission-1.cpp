class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;

        int maxi = -1e5;
        priority_queue<pair<int, int>> pq;

        for(int i = 0; i < k; i++){
            maxi = max(maxi, nums[i]);
            pq.push({nums[i], i});
        }
        ans.push_back(maxi);

        int l = 1;
        for(int r = k; r < n; r++){
            pq.push({nums[r], r});
            while(pq.top().second < l) pq.pop();
            ans.push_back(pq.top().first);
            l++;
        }
        return ans;
    }
};
