class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        int i = 0, j = 0;
        int med = (n + m) / 2 + 1;
        int prev_med = -1;
        int curr_med = -1;

        while(i < n && j < m && med > 0){
            prev_med = curr_med;
            if(nums1[i] > nums2[j]){
                curr_med = nums2[j++];
            }else{
                curr_med = nums1[i++];
            }
            med--;
        }

        while(i < n && med > 0){
            prev_med = curr_med;
            curr_med = nums1[i++];
            med--;
        }

        while(j < m && med > 0){
            prev_med = curr_med;
            curr_med = nums2[j++];
            med--;
        }
        
        if((n+m)%2 == 1){
            return (double)curr_med;
        }else{
            return (curr_med + prev_med)/2.0;
        }
    }
};
