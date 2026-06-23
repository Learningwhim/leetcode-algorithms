class Solution {
public:
    void bs(int x, vector<int> &sub){
        int lo = 0, hi = sub.size();
        while(lo < hi){
            int mid = lo+(hi-lo)/2;
            if(sub[mid] < x){
                lo = mid+1;
            }else hi = mid;
        }
        swap(x, sub[lo]);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> sub;
        for(int i = 0; i < n; ++i){
            if(sub.empty() || sub.back() < nums[i]) sub.push_back(nums[i]);
            else{
                bs(nums[i], sub);
            }
        }
        return sub.size();
    }
};