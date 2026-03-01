class Solution {
public:
    void dfs(vector<vector<int>>& board, int i, int j, int n, int m){
        if(board[i][j] != 1) return;
        board[i][j] = 2;
        if(i > 0) dfs(board, i-1, j, n, m);
        if(j > 0) dfs(board, i, j-1, n, m);
        if(i < n-1) dfs(board, i+1, j, n, m);
        if(j < m-1) dfs(board, i, j+1, n, m);
        return;
    }
    int numEnclaves(vector<vector<int>>& board) {
        int n = board.size();
        int m = board[0].size();

        for(int i = 0; i < n; ++i){
            if(board[i][0] == 1) dfs(board, i, 0, n, m);
            if(board[i][m-1] == 1) dfs(board, i, m-1, n, m);
        }
        for(int i = 0; i < m; ++i){
            if(board[0][i] == 1) dfs(board,  0, i, n, m);
            if(board[n-1][i] == 1) dfs(board,  n-1, i, n, m);
        }
        int ans = 0;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if(board[i][j] == 1) ans++;
                else if(board[i][j] == 2) board[i][j] = 1; 
            }
        }
        return ans;
    }
};