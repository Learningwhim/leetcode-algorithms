class Solution {
public:
    bool poss(vector<vector<char>>& board, char x, int row, int col){
        int r = 3*(row/3);
        int c = 3*(col/3);
        for(int i = r; i < r+3; ++i){
            for(int j = c; j < c+3; ++j){
                if(board[i][j] == x) return false;
            }
        }
        for(int i = 0; i < board.size(); ++i){
            if(board[row][i] == x) return false;
            if(board[i][col] == x) return false;
        }
        return true;
    }
    bool solve(vector<vector<char>>& board){
        int n = board.size();
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                if(board[i][j] == '.'){
                    for(char c = '1'; c <= '9'; ++c){
                        if(poss(board, c, i, j)){
                            board[i][j] = c;
                            if(solve(board)) return true;
                            else board[i][j] = '.';
                        }
                    }
                     return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
        
    }
};