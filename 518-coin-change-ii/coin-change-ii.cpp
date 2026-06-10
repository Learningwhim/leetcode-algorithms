class Solution {
public:
    vector<vector<int>> dp;
    int f(int i, int amount, vector<int>& coins, int n){
        if(amount < 0) return 0;
        if(amount == 0) return 1;
        if(i == n) return 0;
        if(dp[i][amount] != -1) return dp[i][amount];
        
        int take = f(i, amount-coins[i], coins, n);
        int notTake = f(i+1, amount, coins, n);
        
        return dp[i][amount] = take+notTake;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        dp.assign(n+1, vector<int>(amount+1, -1));
        return f(0, amount, coins, n);
    }
};