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
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n*n);
        vector<pair<int,int>> pos(n*n);
        for(int r = 0; r < n; ++r){
            for(int c = 0; c < n; ++c){
                pos[grid[r][c]] = {r, c};
            }
        }
        for(int t = 0; t < n*n; ++t){
            int r = pos[t].first;
            int c = pos[t].second;
            int dr[] = {-1, 0, 0, 1};
            int dc[] = {0, -1, 1, 0};
            for(int k = 0; k < 4; ++k){
                int nr = r + dr[k];
                int nc = c + dc[k];
                if(nr < n && nc < n && nr >= 0 && nc >=0 && grid[nr][nc] <= t){
                    ds.unionByRank(t, grid[nr][nc]);
                }
            }
            if(ds.findUpar(grid[0][0]) == ds.findUpar(grid[n-1][n-1])) return t;
        }
        //return *max_element(grid.begin(), grid.end());
        return grid[0][0];
    }
};