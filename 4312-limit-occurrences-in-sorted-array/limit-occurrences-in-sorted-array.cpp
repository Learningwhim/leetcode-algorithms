class Solution {
public:
    vector<int> limitOccurrences(vector<int>& nums, int k) {
        map<int, int> mp;
        for(int i = 0; i < nums.size(); ++i){
            mp[nums[i]]++;
        }
        vector<int> ans;
        for(auto &each : mp){
            for(int i = 0; i < k; ++i) {
                if(i < each.second) ans.push_back(each.first);
            }
        }
         return ans;
    }
};