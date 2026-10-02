class Solution {
public:
    double power (double x, long long n){
        if(n == 0) return 1;

        double half = power(x, n/2);

        if(n % 2 == 0){
            return half * half;
        }
        return half * half * x;
    }

    double myPow(double x, int n) {

    double ans = 1.0;
    long long nn = n;

    if(nn < 0){
        nn = -1 * nn;
    }
    
    if(n < 0){
        ans = (double)1.0 / (double)(power(x, n));
    }else{
        ans = (double)(power(x, n));
    }    

    return ans;
    }
};