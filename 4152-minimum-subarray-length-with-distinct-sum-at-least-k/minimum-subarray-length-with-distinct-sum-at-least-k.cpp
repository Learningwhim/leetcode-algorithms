class Solution {
public:
    int minLength(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;
        int sum = 0, minlen = INT_MAX;
        int l = 0, r = 0;
        while(r < n){
                mp[nums[r]]++;
            if(mp[nums[r]] == 1) sum += nums[r];
            while(sum >= k){
                
                if(mp[nums[l]] == 1) {
                    sum -= nums[l];
                }
                minlen = min(r-l+1, minlen);
                mp[nums[l]]--;
                l++;
            }
            r++;
        }
        return (minlen == INT_MAX) ? -1 : minlen;
    }
};