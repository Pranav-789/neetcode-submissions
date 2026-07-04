class Solution {
public:
    int findMin(vector<int> &nums) {
        // 3    4   5   6   1   2
        // up   up  up  up  down  up

        // if nums_mid > nums_low => increasing slope




        int low = 0, high = nums.size() -1;

        while(low < high){
            int mid = low + (high - low)/2;

            if(nums[mid] >= nums[high]){
                low = mid + 1;
            }else{
                high = mid;
            }
        }
        return nums[low];
    }
};
