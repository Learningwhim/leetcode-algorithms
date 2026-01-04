class Solution {
public:
    double f(double x, int n){
        if(x == 0) return 0;
        if(n == 0) return 1;
        if(n == 1) return x;
        if(n == -1) return 1/x;
        double prod = f(x, n/2);
        if(n < 0) x = 1/x;
        if(n%2) return x*prod*prod;
        return prod*prod;
    }
    double myPow(double x, int n) {
        return f(x, n);
    }
};