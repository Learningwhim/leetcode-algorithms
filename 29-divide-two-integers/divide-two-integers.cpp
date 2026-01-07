class Solution {
public:
    int divide(int dividend, int divisor) {
        int ans = 0;
        bool flag = true;
        if((dividend > 0 && divisor < 0) ||(dividend < 0 && divisor > 0) ) flag = false;
        long long n = abs(1ll*dividend), d = abs(1ll*divisor);
        while(n >= d){
            int cnt = 0;
            while(n >= d<<(cnt+1)) cnt++;
            ans += 1<<cnt;
            n = n-(d*1<<cnt);
        }
        if(flag && ans == 1<<31) return INT_MAX;
        if(!flag && ans == 1<<31) return INT_MIN;
        return flag ? ans : -ans;
    }
};