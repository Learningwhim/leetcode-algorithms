class Solution {
public:
    void f(vector<vector<int>> &ans, vector<int>& nums, int k, int &count, int sum, int i, vector<int> &v){
        if(i == nums.size()) {
            if(sum == k) ans.push_back(v);
            return;
        }
        if(sum > k) return;
        f(ans, nums, k, count, sum, i+1, v);
        v.push_back(nums[i]);
        f(ans, nums, k, count, sum+nums[i], i, v);
        //f(ans, nums, k, count, sum+nums[i], i+1, v);
        v.pop_back();
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int count = 0, sum = 0;
        vector<vector<int>> ans;
        vector<int> v;
        f(ans, candidates, target, count, sum, 0, v);
        return ans;
    }
};