class Solution {
public:
    
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<pair<int , int>, int>> q;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        int time = 0;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if(grid[i][j] == 2){
                    q.push({{i, j}, 0});
                }
            }
        }
        while(!q.empty()){
                            auto curr = q.front();
                q.pop();
                int x = curr.first.first, y = curr.first.second;
                time = max(curr.second, time);
                if(x < n-1 && !vis[x+1][y] && grid[x+1][y] == 1){
                    vis[x+1][y] = true;
                    q.push({{x+1,y}, curr.second+1});
                }
                if(x > 0 && !vis[x-1][y] && grid[x-1][y] == 1){
                    vis[x-1][y] = true;
                    q.push({{x-1,y}, curr.second+1});
                }
                if(y < m-1 && !vis[x][y+1] && grid[x][y+1] == 1){
                    vis[x][y+1] = true;
                    q.push({{x,y+1}, curr.second+1});
                }
                if(y > 0 && !vis[x][y-1] && grid[x][y-1] == 1){
                    vis[x][y-1] = true;
                    q.push({{x,y-1}, curr.second+1});
                }

        }
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if(grid[i][j] == 1 && !vis[i][j]){
                    return -1;
                }
            }
        }
        return time;
    }
};