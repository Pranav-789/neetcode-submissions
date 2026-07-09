class Solution {
    vector<int> findPSE(vector<int>& arr){
        int n = arr.size();

        stack<int> st;
        vector<int> prevS(n, -1);

        for(int i = 0; i < n; i++){
            while(!st.empty() && arr[i] <= arr[st.top()]){
                st.pop();
            }

            if(!st.empty()){
                prevS[i] = st.top();
            }
            st.push(i);
        }

        while(!st.empty()) st.pop();
        return prevS;
    }

    vector<int> findNSE(vector<int>& arr){
        int n = arr.size();
        stack<int> st;
        vector<int> nextS(n, n);

        for(int i = n-1; i >= 0; i--){
            while(!st.empty() && arr[i] <= arr[st.top()]) st.pop();

            if(!st.empty()) nextS[i] = st.top();

            st.push(i);
        }
        while(!st.empty()) st.pop();
        return nextS;
    }
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int maxArea = 0;
        vector<int> prevS = findPSE(heights);
        vector<int> nextS = findNSE(heights);

        for(int i = 0; i < n; i++){
            maxArea = max(maxArea, heights[i]*(nextS[i]-prevS[i]-1));
        }

        return maxArea;
    }
};
