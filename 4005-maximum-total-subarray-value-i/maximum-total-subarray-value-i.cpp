class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        long long value = 0;
        int n = nums.size();
        int mx = INT_MIN, mn = INT_MAX;
        for(int x : nums){
            mx = max(mx, x);
            mn = min(mn, x);
        }
        
        return 1ll*k*(mx-mn);
    }
};