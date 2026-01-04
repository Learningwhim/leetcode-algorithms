class Solution {
public:
    bool isPalindrome(string s){
        if(s.size() <= 1) return true;
        for(int i = 0; i < s.size()/2; i++){
            if(s[i] != s[s.size()-i-1]) return false;
        }
        return true;
    }
    void f(vector<vector<string>> &ans, vector<string> &v, int ind, string s){
        if(ind == s.size()){
            ans.push_back(v);
            return;
        }
        for(int i = ind; i < s.size(); ++i){
            if(isPalindrome(s.substr(ind, i-ind+1))){
                v.push_back(s.substr(ind, i-ind+1));
                f(ans, v, i+1, s);
                v.pop_back();
            }
        }

    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> v;
         f(ans, v, 0, s);
        return ans;
    }
};