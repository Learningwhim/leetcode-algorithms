class Solution {
public:
    void f(vector<string> &ans, string &s, int i, int n, int open, int close){
        if(i == n) {
            ans.push_back(s);
            return;
        }
        
        if(open < close){
            if(open > 0){s.push_back('(');
            f(ans, s, i+1, n, open-1, close);
            s.pop_back();}
            s.push_back(')');
            f(ans, s, i+1, n, open, close-1);
            s.pop_back();
        }else {
            s.push_back('(');
            f(ans, s, i+1, n, open-1, close);
            s.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s = "(";
        f(ans, s, 0, 2*n-1, n-1, n);
        return ans;
    }
};