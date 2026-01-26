class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>> ans;
        sort(arr.begin(), arr.end());
        int mind = INT_MAX;
        int n = arr.size();
        for(int i = 1; i < n; ++i){
            if(arr[i]-arr[i-1] < mind){
                ans = vector<vector<int>>();
                mind = arr[i]-arr[i-1];
                ans.push_back({arr[i-1], arr[i]});

            }else if(arr[i]-arr[i-1] == mind) ans.push_back({arr[i-1], arr[i]});
        }
        return ans;
    }
};