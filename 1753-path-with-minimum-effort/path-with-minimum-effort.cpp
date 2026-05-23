class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        priority_queue <tuple<int,int,int>,
                        vector<tuple<int,int,int>>,
                        greater<tuple<int,int,int>>> pq;
        if(n == 1 && m == 1) return 0;
        int dx[4] = {-1, 0, 0, 1};
        int dy[4] = {0, 1, -1, 0};
        pq.push({0,0,0});
        dist[0][0] = 0;
        while(pq.size()){
            auto [d, x, y] = pq.top();
            pq.pop();
            for(int i = 0; i < 4; ++i){
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx >= 0 && ny >=0 && nx < n && ny < m){
                    int edgeDiff = abs(heights[x][y]-heights[nx][ny]);
                    int newEffort = max(d, edgeDiff);
                    if(d > dist[x][y]) continue;
                    if(newEffort >= dist[nx][ny]) continue;
                    dist[nx][ny] = newEffort;
                    //if(nx == n-1 && ny == m-1) return dist[nx][ny];
                    pq.push({dist[nx][ny], nx, ny});
                }
            }
        }
        return dist[n-1][m-1];

    }
};