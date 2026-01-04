class Solution {
public:
    void f(vector<vector<int>> &ans, vector<int>& nums, vector<int> &v, int i){
        if(i == nums.size()){
            ans.push_back(v);
            return;
        }
        v.push_back(nums[i]);
        f(ans, nums, v, i+1);
        v.pop_back();
        f(ans, nums, v, i+1);

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> v;
        f(ans, nums, v, 0);
        return ans;
    }
};