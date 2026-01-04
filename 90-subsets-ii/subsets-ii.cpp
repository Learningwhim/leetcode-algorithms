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
        while(i+1 < nums.size() && nums[i+1] == nums[i]) i++;
        f(ans, nums, v, i+1);

    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> v;
        sort(nums.begin(), nums.end());
        f(ans, nums, v, 0);
        return ans;
    }
};