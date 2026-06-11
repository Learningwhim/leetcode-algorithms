class Solution {
public:
    vector<vector<int>> dp;
    
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        dp.assign(n+1, vector<int>(m+1, -1));
        
        for(int i = 0; i <= n; ++i) dp[i][0] = 0;
        for(int i = 0; i <= m; ++i) dp[0][i] = 0;
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= m; ++j){
                int cnt = 0;
                if(text1[i-1] == text2[j-1]) cnt = 1+ dp[i-1][j-1];
                else cnt = max(dp[i-1][j], dp[i][j-1]);
                dp[i][j] = cnt;
            }
        }
        return dp[n][m];
        
    }
};