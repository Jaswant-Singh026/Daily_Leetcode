class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == divisor) return 1;
        if(dividend == INT_MIN && divisor == -1) return INT_MAX;
        if(divisor == 1) return dividend;

        int sign = (dividend < 0) ^ (divisor < 0) ? -1 : 1;

        long n = abs((long)dividend);
        long d = abs((long)divisor);
        int ans = 0;

        while(n >= d){
            int count = 0;
            while(n >= (d << count)){
                n -= (d << count);
                ans += (1 << count);
                count++;
            }
        }
        if(sign == -1){
            return -ans;
        }
        return ans;
    }
};