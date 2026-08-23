class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> ans;
        int st = lower;
        for(int i = 0; i < nums.size(); ++i){
            if(nums[i] < lower || nums[i] > upper) continue;
            if(nums[i] > st) ans.push_back({st, nums[i]-1});
            st = nums[i]+1;
        }
        if(st <= upper){
            ans.push_back({st, upper});
        }
        return ans;
    }
};