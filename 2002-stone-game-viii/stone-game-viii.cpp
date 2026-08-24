class Solution {
public:
    #define MAX 1e5
    vector<int> dp;
    int solve(int i, int n, vector<int> &p){
        if(i >= n) return 0;
        if(dp[i] != -1) return dp[i]; 
        int best = INT_MIN;
        for(int j = i; j < n; ++j){
            int scoreUptoJ = p[j];
            int res = scoreUptoJ - solve(j+1, n, p);
            best = max(res, best);
        }
    return dp[i] = best;
    }
    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();
        vector<int> p(n,0);
        p[0] = stones[0];
        for(int i = 1; i < n; i++) p[i] = p[i-1] + stones[i];
        int dp = p[n-1];
        for(int i = n-2; i >= 1; --i){
            dp = max(dp, p[i]-dp);
        }
        return dp;
    }
};