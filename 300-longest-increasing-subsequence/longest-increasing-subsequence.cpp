class Solution {
public:
    vector<vector<int>> dp;
    int f(int i,int prev, vector<int>& nums){
        if(i ==  nums.size()) return 0;
        if(dp[i][prev+1] != -1) return dp[i][prev+1];
        int skip = f(i+1, prev, nums) ;
        int take = 0;
        if (prev == -1 || nums[i] > nums[prev]) {
            take = 1 + f(i + 1, i, nums);
        }
        return dp[i][prev+1] = max(take, skip);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        dp.assign(n+1, vector<int>(n+1, 0));
        //return f(0, -1, nums);
        for(int i = n-1; i >= 0; --i){
            for(int j = i-1; j >= -1; --j){
                int skip = dp[i+1][j+1] ;
                int take = 0;
                if (j == -1 || nums[i] > nums[j]) {
                    take = 1 + dp[i+1][i+1];
                }
                dp[i][j+1] = max(take, skip); 
            }
        }
        return dp[0][0];
    }
};