class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        if(nums.size() == 0) return 0;
        for(auto it: nums){
            st.insert(it);
        }
        int maxlen = 1;
        for(int x: st){
            if(!st.count(x-1)){
                int len = 1;
                int cur = x;

                while(st.count(cur+1)){
                    len++;
                    cur++;
                }
                maxlen = max(len, maxlen);
            }
        }
        return maxlen;
    }
};
