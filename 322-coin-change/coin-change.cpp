class Solution {
public:
    vector<int> dp;
    const int INF = 1e9;
    int f(int target, vector<int> &coins, int n){
        if(target < 0) return INF;
        if(target == 0 ) return 0;
        if(dp[target] != -1) return dp[target];
        int mini = INF;
        for(int i = 0; i < n; ++i){
            mini = min(mini, 1+f(target-coins[i], coins, n));
        }
        return dp[target] = mini;
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        dp.assign(amount+1, -1);
        int ans = f(amount, coins, n);
        return ans >= 1e9 ? -1 : ans;
    }
};