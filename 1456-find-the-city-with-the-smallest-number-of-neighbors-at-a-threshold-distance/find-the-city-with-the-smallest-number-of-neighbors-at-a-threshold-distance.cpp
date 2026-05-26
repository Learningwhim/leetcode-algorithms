class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<int> nos(n, 0);
        vector<vector<pair<int,int>>> adj(n);
            for(auto e : edges){
                adj[e[0]].push_back({e[1],e[2]});
                adj[e[1]].push_back({e[0],e[2]});
            }
        for(int i = 0; i < n; ++i){
            int cnt = 0;
            
            vector<int> dist(n, INT_MAX);
            dist[i] = 0;
            priority_queue< pair<int,int>,
                            vector<pair<int,int>>,
                            greater<pair<int,int>>> pq;
            pq.push({0, i});
            while(pq.size()){
                auto [d, node] = pq.top(); pq.pop();
                if(d > dist[node]) continue;
                for(auto nd : adj[node]){
                    if( d+nd.second < dist[nd.first]){
                        dist[nd.first] = d+nd.second;
                        pq.push({d+nd.second,nd.first});
                    }
                }
            }
            
            for(int j = 0; j < n; j++){
                if(i != j && dist[j] <= distanceThreshold)
                    cnt++;
            }
            nos[i] = cnt;
        }
        int idx = 0, max = nos[0];
        for(int i = 1; i < n; ++i){
            if(nos[i] <= max) {
                max = nos[i];
                idx = i;
            }
        }
        return idx;

    }
};