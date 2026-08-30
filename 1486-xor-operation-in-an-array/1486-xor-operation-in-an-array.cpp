class Solution {
public:
    int xorTil(int n){
        if(n % 4 == 0) return n;
        else if(n % 4 == 1) return 1;
        else if(n % 4 == 2) return n+1;
        else return 0;
    }
    int xorOperation(int n, int start) {
       int a = start >> 1;
       int result = xorTil(a + n - 1) ^ xorTil(a - 1);
       result = result << 1;

       if((start & 1)&&(n & 1)){
        result ^= 1;
       }
       return result;
    }
};