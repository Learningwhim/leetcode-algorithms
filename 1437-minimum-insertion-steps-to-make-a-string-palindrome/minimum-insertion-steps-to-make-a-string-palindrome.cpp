class Solution {
public:
    vector<vector<int>> dp;
    int minInsertions(string s) {
        string s1 = s;
        reverse(s.begin(), s.end());
        string s2 = s;
        int n = s1.size(), m = s2.size();
        dp.assign(n+1, vector<int> (m+1, 0));
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= m; ++j){
                if(s1[i-1] == s2[j-1]) dp[i][j] = 1+dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }  
        int ans = -1;
        for(int i = 0; i <= n; ++i){
            ans = max(ans,*max_element(dp[i].begin(), dp[i].end()));
        }
        return ((n-ans));
    }
};