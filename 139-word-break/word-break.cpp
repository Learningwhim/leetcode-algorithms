class Solution {
public:
    vector<int> memo;
    bool f(string &s, unordered_set<string> &dict, int ind){
        if(ind == s.size()) return true;
        if(memo[ind] != -1) return memo[ind];
        for(int i = 1; i+ind <= s.size(); ++i){
            
            if( dict.find((s.substr(ind, i))) != dict.end() ){
                if(f(s, dict, ind+i)) return memo[ind] = true;
            }
        }
        return memo[ind] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        unordered_set<string> dict;
        memo.assign(n, -1);
        for(int i = 0; i < wordDict.size(); ++i) dict.insert(wordDict[i]);
        return f(s, dict, 0);
    }
};