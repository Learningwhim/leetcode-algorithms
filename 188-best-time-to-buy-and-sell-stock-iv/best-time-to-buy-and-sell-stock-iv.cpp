class Solution {
public:
    vector<vector<vector<int>>> dp;
    int f(int i, int buy, int cap, vector<int> &p){
        if(i == p.size()) return 0;
        if(cap == 0) return 0;
        if(dp[i][buy][cap] != -1) return dp[i][buy][cap];
        if(buy){
            int profit = -p[i]+ f(i+1, 0, cap, p);
            int skip = f(i+1, 1, cap, p);
            return dp[i][buy][cap] = max(profit, skip);
        }else{

            int sell = p[i] + f(i+1, 1, cap-1, p);
            int hold = f(i+1, 0, cap, p);
            return dp[i][buy][cap] = max(sell, hold);
        }
    }
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        dp.assign(n,vector<vector<int>>(2, vector<int>(k+1, -1)));
        return f(0, 1, k, prices);
    }
};