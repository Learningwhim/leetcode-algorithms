class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);
        queue<int> q;
        for(int i = 0; i < n; ++i){
            if(color[i] == -1){
                q.push(i);
                color[0] = 0;
                while(!q.empty()){
                    int sz = q.size();
                    for(int i = 0; i < sz; ++i){
                        int curr = q.front();
                        q.pop();
                        for(auto neighbour : graph[curr]){
                            if(color[neighbour] == -1){
                                color[neighbour] = 1-color[curr];
                                q.push(neighbour);
                            }
                            else if (color[neighbour] == color[curr]) return false;
                            
                        }
                    }
                }
            }
        }
        return true;
    }
};