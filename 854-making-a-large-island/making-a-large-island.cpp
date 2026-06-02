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
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n*n);
        for(int r = 0; r < n; ++r){
            for(int c = 0; c < n; ++c){
                if(grid[r][c] == 0)continue;
                int dr[] = {-1, 0, 1, 0};
                int dc[] = {0, -1, 0, 1};
                for(int k = 0; k < 4; ++k){
                    int nr = r + dr[k];
                    int nc = c + dc[k];
                    if(nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc] == 1){
                        int node = r*n + c;
                        int adjNode = nr*n+ nc;

                        ds.unionBySize(node, adjNode);
                    }
                }
            }
        }
        int maxsz = 0;
        for(int r = 0; r < n; ++r){
            for(int c = 0; c < n; ++c){
                int sz = 1;
                set<int> parents;
                if(grid[r][c] == 1) continue;
                int dr[] = {-1, 0, 1, 0};
                int dc[] = {0, -1, 0, 1};
                for(int k = 0; k < 4; ++k){
                    int nr = r + dr[k];
                    int nc = c + dc[k];
                    if(nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc] == 1){
                        int node = r*n + c;
                        int adjNode = nr*n+ nc;
                        parents.insert(ds.findUpar(adjNode));
                    }
                }
                for(auto par : parents){
                    sz += ds.size[par];
                }
                maxsz = max(sz, maxsz);
            }
        }
        for(int i = 0; i < n*n; i++){
            maxsz = max(maxsz, ds.size[ds.findUpar(i)]);
        }
        return maxsz;
    }
};