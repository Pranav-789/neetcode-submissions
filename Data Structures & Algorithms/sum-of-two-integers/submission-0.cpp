class Solution {
public:
    int getSum(int a, int b) {
        int carry = 0;
        int ans = 0;
        for(int i = 0; i < 32; i++){
            int ith_bit = carry;
            int ba = ((a >> i) & 1);
            int bb = ((b >> i) & 1);

            ans = ans | ((ith_bit ^ ba ^ bb) << i);
            carry = (bb && ba) || (bb && carry) || (ba && carry);
        }
        return ans;
    }
};
