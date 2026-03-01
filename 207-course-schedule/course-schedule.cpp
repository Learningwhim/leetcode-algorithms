class Solution {
public:
    bool dfs(int n, vector<vector<int>> &mp, vector<int> &vis, int crs){
        if(vis[crs] == 1) return false;
        if(vis[crs] == 2) return true;
        if(mp[crs].size() == 0) return true;
        vis[crs] = 1;
        for(auto each : mp[crs]){
            if(!dfs(n, mp, vis, each)) return false;
        }
        vis[crs] = 2;
        return true;
    }
    bool canFinish(int n, vector<vector<int>>& p) {
        vector<vector<int>> mp(n);
        vector<int> vis(n, 0);
        for(auto each : p){
            mp[each[0]].push_back(each[1]);
        }
        for(int i = 0; i < mp.size(); ++i){
            for(int j = 0; j < mp[i].size(); ++j){
                if(!dfs(n, mp, vis, mp[i][j])) return false;
            }
        }
        return true;

    }
};