class Solution {
public:
    // double f(double x, int n){
    //     if(x == 0) return 0;
    //     if(n == 0) return 1;
    //     if(n == 1) return x;
    //     if(n == -1) return 1/x;
    //     double prod = f(x, n/2);
    //     if(n < 0) x = 1/x;
    //     if(n%2) return x*prod*prod;
    //     return prod*prod;
    // }
    double myPow(double x, long long n) {
        double ans = 1;
        long long m = n;
        n = abs(1ll*n);
        while(n > 0){
            if(n%2){
                ans = ans*x;
                n = n-1;
            }else{
                n = n/2;
                x = x*x;    
            }
        }
        if(m < 0) return 1.0/ans;
        return ans;
    }
};