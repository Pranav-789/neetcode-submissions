class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0, high = nums.size()-1;

        while(low <= high){
            int mid = low + (high - low)/2;

            if(nums[mid] == target) return mid;

            // 3    4   5   6   1   2
            // low     mid          high
            // currently n_low < n_mid, see if target lies in this range =>high = mid -1; -> sorted region
            // else low = mid + 1
            // 6    1   2
            // l    m   h

            if(nums[mid] >= nums[low]){
                if(nums[low] <= target && target < nums[mid]){
                    high = mid - 1;
                }else{
                    low = mid + 1;
                }
            }else{
                if(target < nums[mid] || target > nums[high]){
                    high = mid - 1;
                }else{
                    low = mid + 1;
                }
            }
        }
        return -1;
    }
};
