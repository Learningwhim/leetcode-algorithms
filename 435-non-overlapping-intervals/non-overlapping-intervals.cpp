class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        vector<pair<int, int>> v;
        int n = intervals.size();
        for(int i = 0; i < n; ++i){
            v.push_back({intervals[i][0], intervals[i][1]});
        }
        sort(v.begin(), v.end(), [](auto &a, auto&b){
            if(a.second == b.second) return a.first > b.first;
            return a.second < b.second;
        });
        int cnt = 1, freetime = v[0].second;
        for(int i = 1; i < n; ++i){
            if(v[i].first >= freetime){
                cnt++;
                freetime = v[i].second;
            }
        }
        return n-cnt;
    }
};