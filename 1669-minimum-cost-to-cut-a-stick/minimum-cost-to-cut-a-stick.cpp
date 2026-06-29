class Solution {
public:
    vector<vector<int>> dp;
    int f(int i, int j, vector<int>  &cuts){
        if(i > j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int mini = INT_MAX;
        for(int k = i; k <= j; ++k){
            int cost = cuts[j+1]-cuts[i-1] + f(i,k-1, cuts) + f(k+1, j, cuts);
            mini = min(mini, cost);
        }
        return dp[i][j] = mini;
    }
    int minCost(int n, vector<int>& cuts) {
        
        cuts.push_back(0);
        cuts.push_back(n);
        int m = cuts.size();
        dp.assign(m, vector<int>(m, -1));
        sort(cuts.begin(),cuts.end());
        return f(1, m-2, cuts);
    }
};