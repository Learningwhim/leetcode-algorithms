class Solution {
public:
    int jump(vector<int>& nums) {
        int curr = 0, jumpct = 0, farthest = 0;
        int n = nums.size();
        vector<int> dp(n, 1e9);
        dp[0] = 0;
        for(int i = 0; i < n-1; ++i){
            farthest = max(farthest, i+nums[i]);
            if(i == curr){
                curr = farthest;
                jumpct++;
            }
        }
        return jumpct;
    }
};