class Solution {
public:
    long long digitsum(int n){
        long long sum = 0;
        long long product = 1;
        while(n > 0){
            sum += n%10;
            product *= n%10;
            n /= 10;
        }
        return sum+product;
    }
    bool checkDivisibility(int n) {
        return (n%digitsum(n)) == 0;
    }
};