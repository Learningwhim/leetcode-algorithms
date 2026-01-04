class Solution {
public:
   
    void f(string digits, vector<string> &ans, string &s, int i,unordered_map<char, string> &m){
        if(i == digits.size()){
            ans.push_back(s);
            return;
        }
        char c = digits[i];
        for(int j = 0; j < m[c].size(); ++j){
            s.push_back(m[c][j]);
            f(digits, ans, s, i+1, m);
            s.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
         unordered_map<char,string> m;
    m['2'] = "abc";
    m['3'] = "def";
    m['4'] = "ghi";
    m['5'] = "jkl";
    m['6'] = "mno";
    m['7'] = "pqrs";
    m['8'] = "tuv";
    m['9'] = "wxyz";
        vector<string> ans;
        string s = "";
        f(digits, ans, s, 0, m);
        return ans;
    }
};