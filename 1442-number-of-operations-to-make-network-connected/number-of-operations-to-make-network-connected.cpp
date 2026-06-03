class Solution {
public:
    //int cnt = 0;
    class DisjointSet{
        public:
        vector<int> rank, parent;
        DisjointSet(int n){
            rank.resize(n, 0);
            parent.resize(n);
            for(int i = 0;  i < n; ++i) parent[i] = i;
        }
        int findUpar(int node){
            if(node == parent[node]) return node;
            return parent[node] = findUpar(parent[node]);
        }
        int unionByRank(int u, int v){
            int ulp_u = findUpar(u);
            int ulp_v = findUpar(v);
            if(ulp_u == ulp_v) return 1;
            if(rank[ulp_v] < rank[ulp_u]){
                parent[ulp_u] = ulp_v;
            }else if(rank[ulp_v] < rank[ulp_u]){
                parent[ulp_v] = ulp_u;
            }else{
                parent[ulp_v] = ulp_u;
                rank[ulp_u]++;
            }
            return 0;
        }
    };
    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<int> vis(n, 0);
        DisjointSet ds(n);
        int cnt = 0;
        int cc = 0;
        for(auto c : connections){
        if(ds.findUpar(c[0]) == ds.findUpar(c[1])) cnt++;
        else ds.unionByRank(c[0], c[1]);
        }
        for(int i = 0; i < n; ++i) if(ds.parent[i] == i) cc++;

        return cnt >= cc-1 ? cc-1 : -1;
    }
};