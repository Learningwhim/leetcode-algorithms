class Solution {
public:
    vector<int> dp;
    vector<int> cnt;
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        dp.assign(n, 1);
        cnt.assign(n, 1);
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < i; ++j){
                if(nums[j] < nums[i]){
                    if(dp[j]+1 > dp[i]){
                        dp[i] = dp[j]+1;
                        cnt[i] = cnt[j];
                    }else if(dp[j]+1 == dp[i]){
                        cnt[i] += cnt[j];
                    }
                }
            }
        }
        int ans = 0;
        int maxi = *max_element(dp.begin(),dp.end());
        for(int i = 0; i < n; ++i){
            if(dp[i] == maxi){
                ans += cnt[i];
            }
        }
        return ans;
    }
};