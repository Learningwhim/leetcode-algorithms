class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int sum = 0;
        int n = nums.size();
        unordered_map<int,int> mp;
        for(int i = 0; i < n; ++i) 

        for(int i = 0; i < n; ++i){
            if(mp.find(target-nums[i]) != mp.end()) return {i, mp[target-nums[i]]};
            mp[nums[i]] = i;
        }
        return {};
    }
};