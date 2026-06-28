class Solution {
    vector<vector<int>> results;

    void solve(int index, vector<int>& nums, vector<int>& ans, vector<int>& visited){
        if(index == nums.size()){
            results.push_back(ans);
            return;
        }

        for(int i = 0; i < nums.size(); i++){
            if(!visited[i]){
                if(i > 0 && nums[i] == nums[i-1] && !visited[i-1]) continue;
                ans.push_back(nums[i]);
                visited[i] = 1;
                solve(index+1, nums, ans, visited);
                visited[i] = 0;
                ans.pop_back();
            }
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> ans;
        vector<int> visited(nums.size(), 0);
        sort(nums.begin(), nums.end());
        solve(0, nums, ans, visited);
        return results;
    }
};