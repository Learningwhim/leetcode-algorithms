class Solution {
public:
    class DisjointSet{
        public:
        vector<int> rank, parent, size;

        DisjointSet(int n){
            rank.resize(n, 0);
            size.resize(n, 1);
            parent.resize(n);
            for(int i = 0; i < n; ++i) parent[i] = i;
        }

        int findUpar(int node){
            if(node == parent[node]) return node;
            return parent[node] = findUpar(parent[node]);
        }

        void unionByRank(int u, int v){
            int ulp_u = findUpar(u);
            int ulp_v = findUpar(v);
            if(ulp_v == ulp_u) return;
            if(rank[ulp_u] < rank[ulp_v]){
                parent[ulp_u] = ulp_v;
            }else if(rank[ulp_v] < rank[ulp_u]){
                parent[ulp_v] = ulp_u;
            }else{
                parent[ulp_u] = ulp_v;
                rank[ulp_v]++;
            }
        }

        void unionBySize(int u, int v){
            int ulp_u = findUpar(u);
            int ulp_v = findUpar(v);
            if(ulp_v == ulp_u) return;
            if(size[ulp_u] < size[ulp_v]){
                parent[ulp_u] = ulp_v;
                size[ulp_v] += size[ulp_u];
            }else if(size[ulp_v] < size[ulp_u]){
                parent[ulp_v] = ulp_u;
                size[ulp_u] += size[ulp_v];
            }else{
                parent[ulp_u] = ulp_v;
                size[ulp_v] += size[ulp_u];
            }
        }
    };
    int findCircleNum(vector<vector<int>>& adj) {
        int n = adj.size();
        DisjointSet ds(n+1);
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                if(adj[i][j]) ds.unionByRank(i, j);
            }
        }
        int cnt = 0;
        for(int i = 0; i < n; ++i){
            if(ds.findUpar(i) == i) cnt++;
        }
        return cnt;

    }
};