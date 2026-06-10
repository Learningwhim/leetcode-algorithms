class Solution {
public:
    int total = 0;
    vector<string> ans;
    void solve(int pos, int len, int k, bool flag, string &s){
        if(k > total) return;
        if(pos == len) {
            ans.push_back(s);
            return;
        }
        s += '0';
        solve(pos+1, len, k, false, s);
        s.pop_back();
        if(!flag){
            s += '1';
            solve(pos+1, len, k+pos, true, s);
            s.pop_back();
        }
    }
    vector<string> generateValidStrings(int n, int k) {
        total = k;
        string s;
        solve(0, n, 0, false, s);
        return ans;
    }
};