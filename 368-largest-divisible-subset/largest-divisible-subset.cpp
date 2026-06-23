class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& arr) {
        int n = arr.size();
        vector<int> parent(n, -1);
        sort(arr.begin(), arr.end());
        vector<int> dp(n+1, 0);
        for(int i = 0; i < n; ++i){
            dp[i] = 1;
            for(int j = 0; j < i; ++j){
                
                int take = 0;
                int skip = dp[i];
                if((arr[i] % arr[j] == 0) && dp[j]+1 > dp[i]){
                    take = 1+dp[j];
                    parent[i] = j;
                }
                dp[i] = max(skip, take);
            }
        }
        int last = 0;
        for(int i = 1; i < n; ++i) {
            if(dp[i] > dp[last]) last = i;
        }
        
        vector<int> ans;
        while(last != -1){
            ans.push_back(arr[last]);
            last = parent[last];
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};