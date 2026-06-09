class Solution {
public:
    vector<vector<int>> dp;
    int offset  = 1000;
    int f(int i, int target, vector<int> &nums){
        if(target < -1000 || target > 1000)
    return 0;
        if(i == 0){
            if(nums[i] == 0 && target == 0) return 2;
            if(nums[i] == target || target == -nums[0]) return 1;
            return 0;
        }
        if(dp[i][target+offset] != -1) return dp[i][offset+target];
        int add = f(i-1, target-nums[i], nums);
        int subtract = f(i-1, target+nums[i], nums);
        return dp[i][target+offset] = add+subtract;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        dp.resize(n+1, vector<int> (2001, -1));
        return f(n-1, target, nums);
        
    }
};