class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int l = 0, r = n - 1;
        int maxamt = 0;
        while(l < r){
            int prod = (r-l)*min(heights[l], heights[r]);
            
            maxamt = max(maxamt, prod);

            if(heights[l] < heights[r]) l++;
            else r--;
        }
        return maxamt;
    }
};
