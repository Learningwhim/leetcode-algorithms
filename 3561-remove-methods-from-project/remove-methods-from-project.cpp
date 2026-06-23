class Solution {
public:
    vector<int> vis;
    void dfs( vector<vector<int>> &adj, int k){
        vis[k] = 1;
        for(int child : adj[k]){
            if(!vis[child])dfs(adj, child);
        }
    }
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& inv) {
        vector<vector<int>> adj(n+1);
        for(auto each : inv){
            adj[each[0]].push_back(each[1]);
        }
        vis.resize(n+1, 0);
        dfs(adj, k);
        bool sus = false;
        for(int i = 0; i < n; ++i){
            if(!vis[i]){
                for(auto it : adj[i]){
                    if(vis[it]) sus = true;
                }
            }
        }
        vector<int> ans;
        if(!sus){
             for(int i = 0; i < n; ++i) if(!vis[i]) ans.push_back(i);
        }else{
            for(int i = 0; i < n; ++i)ans.push_back(i);
        }
        return ans;
    }
};