class Solution {
public:
    vector<vector<int>> dp;
    int f(int i, int j, vector<int> &a){
        if(i > j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int maxi = 0;
        for(int k = i; k <= j; ++k){
            int coins = a[i-1]*a[k]*a[j+1] + f(i, k-1, a) + f(k+1, j, a);
            maxi = max(maxi, coins);
        }
        return dp[i][j] = maxi;
    }
    int maxCoins(vector<int>& nums) {
        vector<int> arr;
        arr.push_back(1);
        for(int i = 0; i < nums.size(); ++i) arr.push_back(nums[i]);
        arr.push_back(1);
        int n = nums.size();
        dp.assign(n+2, vector<int> (n+2, -1));
        return f(1, nums.size(), arr);
    }
};