class Solution {
public:
    bool dfs(int n, vector<vector<int>> &mp, vector<int> &vis, vector<int> &pathVis, int crs, vector<int> &ans){
        if(vis[crs] && pathVis[crs]) {
            return true;
        }
        vis[crs] = 1;
        pathVis[crs] = 1;
        
        for(auto each : mp[crs]){
            if(pathVis[each]) return true;
            if(vis[each] == 0) {
                if(dfs(n, mp, vis, pathVis, each, ans)) return true;
            }
        }
        pathVis[crs] = 0;
        ans.push_back(crs);
        return false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<int> ans;
        vector<int> vis(n, 0);
        vector<int> pathVis(n, 0);
        queue<int> q;
        vector<vector<int>> mp(n);
        for (auto& pre : prerequisites) { mp[pre[1]].push_back(pre[0]); }
        for(int i = 0; i < n; ++i){
            if(!vis[i])
                if(dfs(n, mp, vis, pathVis, i, ans)) return {};
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};