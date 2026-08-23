class Solution {
public:
    bool ispal(string ans){
        int n = ans.size();
        for(int i = 0; i <= n/2; ++i){
            if(ans[i] != ans[n-i-1]) return false;
        }
        return true;
    }
    bool isPalindromic(string s) {
        vector<string> st;
        for(auto &each : s){
            st.push_back(bitset<8>(each).to_string());
        }
        string ans = "";
        for(auto each : st) ans += each;
        return ispal(ans);
    }
};