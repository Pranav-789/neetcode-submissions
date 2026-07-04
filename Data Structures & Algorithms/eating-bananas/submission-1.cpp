class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int high = -1;
        for(int i = 0; i < piles.size(); i++) high = max(high, piles[i]);

        int low = 1;

        int ans = INT_MAX;
        while(low <= high){
            int mid = low + (high - low)/2;
            int cnt = 0;
            for(int i = 0; i < piles.size(); i++){
                cnt += (piles[i] + (mid-1))/mid;
            }

            if(cnt > h){
                low = mid + 1;
            }else{
                ans = min(ans, mid);
                high = mid - 1;
            }
        }
        return ans;
    }
};
