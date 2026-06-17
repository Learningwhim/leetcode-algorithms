class Solution {
public:
    vector<vector<int>> dp;
    int f(int i, int canBuy, vector<int>& price){
        if(i == price.size()) return 0;
        if(dp[i][canBuy] != -1) return dp[i][canBuy];
        if(canBuy){
            int buy = -price[i] +  f(i+1, 0, price);
            int skip = f(i+1, 1, price);
            return dp[i][canBuy] = max(buy, skip);
        }else{
            int sell = price[i] +f(i+1, 1, price);
            int hold = f(i+1, 0, price);
            return dp[i][canBuy] = max(sell, hold);
        }
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        dp.assign(n+1, vector<int>(2, -1));
        return f(0, 1, prices);
    }
};