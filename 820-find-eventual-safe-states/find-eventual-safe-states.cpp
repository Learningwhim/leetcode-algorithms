class Solution {
public:
    bool safe(int node, vector<vector<int>> &graph, vector<int>& ans, vector<int> &vis, vector<int> &pvis){
        if(vis[node] && pvis[node]) return true;
        vis[node] = 1;
        pvis[node] = 1;
        for(auto each : graph[node]){
            if(pvis[each]) return true;
            if(!vis[each]) if(safe(each, graph, ans, vis, pvis)) return true;
        }
        pvis[node] = 0;
        ans.push_back(node);
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> ans;
        vector<int> vis(n,0);
        vector<int> pvis(n,0);
        for(int i = 0; i < n; ++i){
            if(!vis[i]) if(safe(i, graph, ans, vis, pvis)) continue;
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};