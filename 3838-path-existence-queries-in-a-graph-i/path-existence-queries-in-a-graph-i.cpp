class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<bool> ans;
        vector<int> par(n, -1);
        par[0] = 0;
        for(int i = 1; i < n; ++i){
            if(abs(nums[i]-nums[i-1]) <= maxDiff){
                par[i] = par[i-1];
            }else{
                par[i] = i;
            }
        }

        for(auto &q : queries){
            if(par[q[0]] != par[q[1]])  ans.push_back(false);
            else ans.push_back(true);
        }
        return ans;
    }
};