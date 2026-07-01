class Solution {
public:
vector<int> dp;
vector<vector<bool>> pal;
    int f(int i, string &s){
        if(i == s.size()) return 0;
        if(dp[i] != -1) return dp[i];
        int ans = INT_MAX;
        //string temp = "";
        for(int k = i; k < s.size(); ++k){
            //temp += s[k];
            if(pal[i][k]) ans = min(ans, 1+f(k+1, s));
        }
        return dp[i] = ans;
    }
    int minCut(string s) {
        int n = s.size();
        dp.assign(n, -1);
        pal.assign(n, vector<bool>(n, false));
        for(int i = 0; i < n; ++i) pal[i][i] = true;
        for(int i = 0; i+1 < n; ++i){
            if(s[i]==s[i+1]) pal[i][i+1] =true;
        }
        for (int len = 2; len < n; len++) {
            for (int i = 0; i + len < n; i++) {
                int j = i + len;
                if(s[i] == s[j] && pal[i+1][j-1]) pal[i][j] = true;
            }
        }
        //for(int i = 0; i < n; ++i) dp[n-1] = 1;
        return f(0, s)-1;
    }
};