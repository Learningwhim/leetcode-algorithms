class Solution {
public:
    vector<string> ans;
    void solve(string s, int target, int i, string path, long long eval, long long last){
        if(i ==  s.length()){
            if(eval == target){
                ans.push_back(path);
                return;
            }
        }
        string currStr;
        long long num = 0;
        for(int j = i; j < s.size(); ++j){
            if(j > i && s[i] == '0' ) break;
            currStr += s[j];
            num = num*10 + s[j]-'0';
            if(i == 0) {
                solve(s, target, j+1, path+ currStr, num, num);
                //solve(s, target, j+1, '-'+path+currStr, -num, -num);
            }
            else{
                solve(s, target, j+1, path+'+'+currStr, eval+num, num);
                solve(s, target, j+1, path+'-'+currStr, eval-num, -num);
                solve(s, target, j+1, path+'*'+currStr, eval-last+last*num, last*num);
            }
        }
    }
    vector<string> addOperators(string num, int target) {
        solve(num, target, 0, "", 0, 0);
        return ans;
    }
};