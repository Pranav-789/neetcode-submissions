class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int, int>> st;
        int n = temperatures.size();
        vector<int> v(n, -1);

        for(int i = 0; i < n; i++){
            while(!st.empty() && st.top().first < temperatures[i]){
                v[st.top().second] = i-st.top().second;
                st.pop();
            }
            st.push({temperatures[i], i});
        }

        for(int i = 0; i < n; i++){
            v[i] = max(0, v[i]);
        }
        return v;
    }
};
