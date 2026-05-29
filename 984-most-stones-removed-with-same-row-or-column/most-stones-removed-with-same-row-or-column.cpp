class Solution {
public:
    class DisjointSet{
        public:
        vector<int> rank, parent, size;
        DisjointSet(int n){
            rank.resize(n+1, 0);
            size.resize(n+1, 1);
            parent.resize(n+1);
            for(int i = 0;  i <= n; ++i) parent[i] = i;
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
        void unionBySize(int u, int v){
            int ulp_u = findUpar(u);
            int ulp_v = findUpar(v);
            if(ulp_u == ulp_v) return;
            if(size[ulp_v] < size[ulp_u]){
                parent[ulp_v] = ulp_u;
                size[ulp_u] += size[ulp_v];
            }else{
                parent[ulp_u] = ulp_v;
                size[ulp_v] += size[ulp_u];
            }
        }
    };
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        int maxr = 0;
        int maxc = 0;
        for(int i = 0; i < n; ++i){
            if(stones[i][0] > maxr) maxr = stones[i][0];
            if(stones[i][1] > maxc) maxc = stones[i][1];
        }
        DisjointSet ds(maxc+maxr+1);
        unordered_map<int,int> mp;
        for(auto s : stones){
            int noder = s[0];
            int nodec = s[1]+maxr +1;
            ds.unionBySize(noder, nodec);
            mp[noder] = 1;
            mp[nodec] = 1;
        }
        int cnt = 0;
        for(auto it : mp){
            if(ds.findUpar(it.first) == it.first) cnt++;
        }
        return n-cnt;
    }
};