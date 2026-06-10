class Solution {
public:
    int sumOfGoodIntegers(int n, int k) {
        int sum = 0;
        for(int x = 0; x <= 10000; ++x){
            if(abs(n-x) <=k && (n&x) == 0) sum += x;
        }
        return sum;
    }
};