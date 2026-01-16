class Solution {
public:
    int jump(vector<int>& nums) {
        int curr = nums[0], jumpct = 0;
        int n = nums.size();
        vector<int> dp(n, 1e9);
        dp[0] = 0;
        for(int i = 0; i < n; ++i){
            for(int j = i+1; j < n && j <= i+nums[i]; ++j){
                dp[j] = min(dp[j], dp[i]+1);
            }
        }
        return dp[n-1];
    }
};