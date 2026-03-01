class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        const int INF = 1e7+7;
        vector<vector<int>> dist(n, vector<int>(m, 0));
        queue<pair<int, int>> q;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if(mat[i][j] == 1) dist[i][j] = INF;
                if(mat[i][j] == 0) q.push({i, j});
            }
        }
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            if(x > 0 && dist[x-1][y] == INF) {
                dist[x-1][y] = dist[x][y]+1;
                q.push({x-1, y});
            }
            if(y > 0 && dist[x][y-1] == INF) {
                dist[x][y-1] = dist[x][y]+1;
                q.push({x, y-1});
            }
            if(x < n-1 && dist[x+1][y] == INF) {
                dist[x+1][y] = dist[x][y]+1;
                q.push({x+1, y});
            }
            if(y < m-1 && dist[x][y+1] == INF) {
                dist[x][y+1] = dist[x][y]+1;
                q.push({x, y+1});
            }

        }
        return dist;
    }
};