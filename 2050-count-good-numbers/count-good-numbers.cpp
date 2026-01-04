class Solution {
public:
    long long m = 1e9+7;
    long long f(long long x, long long n){
        if(x == 0) return 0;
        if(n == 0) return 1;
        if(n == 1) return x;
        if(n == -1) return 1/x;
        long long prod = f(x, n/2);
        if(n < 0) x = 1/x;
        if(n%2) return ((x*prod)%m*prod)%m;
        return (prod*prod)%m;
    }
    int countGoodNumbers(long long n) {
        
        long long sum = 1;
        if(n%2){
            sum = sum*(f((long long)5, (n/2)+1)%m)%m;
            sum = sum*(f(4, (n/2))%m)%m;
        }else{
            sum = sum*(f(5, (n/2))%m)%m;
            sum = sum*(f(4, (n/2))%m)%m;
        }
        return sum;
    }
};