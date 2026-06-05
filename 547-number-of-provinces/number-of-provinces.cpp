class Solution {
public:
    
    void dfs(int node,vector<bool> &vis, vector<vector<int>> &graph){
        if(vis[node]) return;
        vis[node] = true;
        for(auto adj : graph[node]){
            dfs(adj, vis, graph);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        vector<bool> vis;
        vector<vector<int>> graph;
        int n = isConnected.size();
        vis.assign(n, false);
        graph.assign(n, vector<int>());
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                
                if(isConnected[i][j] == 1) graph[i].push_back(j);
            }
        }
        int count = 0;
        for(int i = 0; i < n; ++i){ // we will try dfs from each node
            if(vis[i]) continue;
            count++;
            dfs(i, vis, graph);
        }
        return count;
    }
};