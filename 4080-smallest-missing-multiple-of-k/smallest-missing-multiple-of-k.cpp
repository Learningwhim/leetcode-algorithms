class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int curr = k;
        int n = nums.size();
        nums.push_back(nums[n-1]);
        n++;
        unordered_set<int> st;
        for(int i = 0; i < n; ++i){
            if(curr <= nums[i]){
                if(curr < nums[i] && i < 1) return curr;
                else if(curr != nums[i] && i >= 1 && nums[i-1] < curr) return curr;
                curr += k;
            }
        }
        return curr;
    }
};