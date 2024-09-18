class Solution {
public:
    double myPow(double x, int n) {
        // using the binomial exponentiation logic 
        double a = x;
        double ans = 1.0;
        int sign = (n<0)?1:0;
        n = abs(n);
        while(n){
            if(n&1){
                ans = ans*a;
            }
            a = a*a;
            n = n>>1;
        }
        if(sign==1)
            return 1.0/ans;
        return ans;
    }
};