class Solution {
public:
    int reverse(int x) {
        int sign = 1;
        if(x < 0){
            sign = -1;
            x = -x;
        }

        long long newNum = 0;

        while(x){
            int r = x%10;
            newNum = newNum*10 + r;
            x/=10;
        }

        newNum *= sign;

        if(newNum > INT_MAX || newNum < INT_MIN) return 0;

        return newNum;
    }
};
