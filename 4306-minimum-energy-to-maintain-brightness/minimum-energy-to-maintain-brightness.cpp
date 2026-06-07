class Solution {
public:
    long long minEnergy(int n, int brightness, vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        for(auto arr : intervals){
            if(ans.empty() || ans.back()[1] < arr[0]) ans.push_back(arr);
            else ans.back()[1] = max(ans.back()[1], arr[1]);
        }
        long long total = 0;
        for(auto each : ans){
            total += each[1]-each[0]+1;
        }
        //if(brightness == 1) return total*brightness;
        return total*((brightness+2)/3);
    }
};