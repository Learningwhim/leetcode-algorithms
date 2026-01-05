class Solution {
public:

    bool isSafe(vector<string> &v, int row, int col){
        int n = v.size();
        for(int i = 0; i < row; ++i){
            if(v[i][col] == 'Q') return false;
        }
        for(int r = row-1, c = col-1; r >=0 && c >= 0; --r, --c){
            if(v[r][c] == 'Q') return false;
        }
        for(int r = row-1, c = col+1; r >=0 && c <= v.size()-1; --r, ++c){
            if(v[r][c] == 'Q') return false;
        }
        return true;
    }

    void f(vector<vector<string>> &ans, vector<string> &v, int row, int n){
        if(row == n) {
            ans.push_back(v);
            return;
        }
        for(int i = 0; i < n; ++i){
            if(isSafe(v, row, i)){
                v[row][i] = 'Q';
                f(ans, v, row+1, n);
                v[row][i] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));
        f(ans, board, 0, n);
        return ans;
    }
};