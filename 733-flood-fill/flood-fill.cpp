class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        queue<pair<int, int>> q;
        int n = image.size();
        int m = image[0].size();
        q.push({sr, sc});
        int currc = image[sr][sc];
        if(color == currc) return image;
        image[sr][sc] = color;
        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            int i = curr.first, j = curr.second;
            if(i < n-1 && image[i+1][j] == currc){
                image[i+1][j] = color;
                q.push({i+1, j});
            }
            if(i > 0 && image[i-1][j] == currc){
                image[i-1][j] = color;
                q.push({i-1, j});
            }
            if(j < m-1 && image[i][j+1] == currc){
                image[i][j+1] = color;
                q.push({i, j+1});
            }
            if(j > 0 && image[i][j-1] == currc){
                image[i][j-1] = color;
                q.push({i, j-1});
            }
        }


        return image;
    }
};