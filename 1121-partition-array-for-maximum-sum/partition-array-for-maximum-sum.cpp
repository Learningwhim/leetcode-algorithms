class Solution {
public:
    vector<int> dp;
    int f(int i, vector<int>& arr, int k){
        if(i >= arr.size()) return 0;
        if(dp[i] != -1) return dp[i]; 
        int ans = 0;
        for(int len = 1; len <= k; ++len){
            int j = i+len-1;
            if(j >= arr.size()) break;
            int maxe = *max_element(arr.begin()+i, arr.begin()+j+1);
            ans = max(ans, len*maxe+f(i+len, arr, k));
        }
        return dp[i] = ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        dp.assign(n, -1);
        return f(0, arr, k);

    }
};