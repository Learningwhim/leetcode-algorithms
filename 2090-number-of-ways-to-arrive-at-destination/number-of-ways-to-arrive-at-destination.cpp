class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        int mod = 1e9+7;
        vector<long long> ways(n, 0);
        vector<long long> dist(n, LLONG_MAX);
        vector<vector<pair<long long,long long>>> adj(n);
        for(auto r : roads){
            adj[r[0]].push_back({r[1],r[2]});
            adj[r[1]].push_back({r[0],r[2]});
        }
        ways[0] = 1;
        dist[0] = 0;
        priority_queue< pair<long long,long long>,
                        vector<pair<long long,long long>>,
                        greater<pair<long long,long long>>> pq;
        pq.push({0, 0});
        while(pq.size()){
            auto [d , node] = pq.top();
            pq.pop();
            if(d > dist[node]) continue;
            for(auto each : adj[node]){
                
                if(d + each.second < dist[each.first]){
                    dist[each.first] = d+each.second;
                    ways[each.first] = ways[node];
                    pq.push({d+each.second, each.first});
                }else if(d + each.second == dist[each.first]){
                    dist[each.first] = d+each.second;
                    ways[each.first] = (ways[each.first]+ways[node]%mod);
                    //pq.push({d+each.second, ways[each.first]});
                }
            }
        }
        
        return ways[n-1]%mod;
    }
};