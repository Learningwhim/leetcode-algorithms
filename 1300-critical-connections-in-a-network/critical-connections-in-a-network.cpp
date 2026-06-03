class Solution {
public:
    vector<int> tin;
    vector<int> low;
    vector<vector<int>> ans;
    vector<int> vis;
    int timer = 1;
    void dfs(int node, int parent, vector<vector<int>>& c){
        vis[node] = 1;
        tin[node] = low[node] = timer++;
        for(auto n : c[node]){
            if(n == parent)continue;
            if(!vis[n]){
                dfs(n, node, c);
                low[node] = min(low[n], low[node]);
                if(low[n] > tin[node]){
                    ans.push_back({node, n});
                }
            }else{
                low[node] = min(low[node], low[n]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& c) {
        vis.resize(n, 0);
        tin.resize(n, 0);
        low.resize(n, INT_MAX);
        vector<vector<int>> adj(n);
        for(auto each : c){
            adj[each[0]].push_back(each[1]);
            adj[each[1]].push_back(each[0]);
        }
        dfs(0, 0, adj);
        return ans;
    }
};