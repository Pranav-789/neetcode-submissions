class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int xor_ = 0;

        for(int i = 0; i < nums.size(); i++){
            xor_ = xor_^nums[i]^i;
        }
        xor_ = xor_^nums.size();

        return xor_;
    }
};
