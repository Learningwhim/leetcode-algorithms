class Solution {
public:
    vector<vector<int>> dp;
    int f(int i, int can, vector<int>& prices, int fee){
        if(i == prices.size()) return 0;
        if(dp[i][can] != -1) return dp[i][can];
        if(can){
            int buy = -prices[i] + f(i+1, 0, prices, fee);
            int skip = f(i+1, 1, prices, fee);
            return dp[i][can] = max(buy, skip);
        }else{
            int sell = prices[i]-fee + f(i+1, 1, prices, fee);
            int hold = f(i+1, 0, prices, fee);
            return dp[i][can] = max(sell, hold);
        }
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();

        dp.assign(n+1, vector<int> (2, -1));
        return f(0, 1, prices, fee);
    }
};