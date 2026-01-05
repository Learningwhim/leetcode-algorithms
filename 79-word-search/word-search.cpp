class Solution {
public:
    // i and j for grid and k for word;
    bool f(vector<vector<char>>& board, string word, int i, int j, int k, int n, int m){
        if(k >= word.size()) return true;
        if(board[i][j] == '#') return false;
        bool up = false, down = false, right = false, left = false;
        if(board[i][j] == word[k]){
            if(k+1 == word.size()) return true;
            char temp = board[i][j];
            board[i][j] = '#';
            
            if(i > 0)  up = f(board, word, i-1, j, k+1, n, m);
            if(j > 0) left = f(board, word, i, j-1, k+1, n, m);
            if(i < n-1) down =  f(board, word, i+1, j, k+1, n, m);
            if(j < m-1) right = f(board, word, i, j+1, k+1, n, m);
             board[i][j] = temp;
        }
        return (up || down || right || left);
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if(board[i][j] == word[0]) {
                    if(f(board, word, i, j, 0, n, m)) return true;
                }
            }
        }
        return false;
    }
};