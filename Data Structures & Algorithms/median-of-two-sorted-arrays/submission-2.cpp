class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() > nums2.size())
            return findMedianSortedArrays(nums2, nums1);
        int n = nums1.size();
        int m = nums2.size();

        int low = 0, high = n;

        int bound = (n+m+1)/2;

        while(low <= high){
            int ea = low + (high - low)/2;
            int eb = bound - ea;

            int l1 = (ea > 0) ? nums1[ea - 1] : INT_MIN;
            int l2 = (eb > 0) ? nums2[eb - 1] : INT_MIN;

            int r1 = (n - ea > 0) ? nums1[ea] : INT_MAX;
            int r2 = (m - eb > 0) ? nums2[eb] : INT_MAX;

            if(l1 > r2) high = ea - 1;
            else if(l2 > r1) low = ea + 1;
            else{
                if((n+m)%2){
                    return max(l1, l2);
                }else{
                    return ((max(l1, l2) + min(r1, r2))/2.0);
                }
            }
        }

        return 0.0;
    }
};
