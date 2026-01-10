class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        int n = num.size(), r = 0;
        st.push(num[0]);
        for(int i = 1; i < n; ++i){
            while(r < k && !st.empty() && st.top() > num[i] ){
                st.pop();
                r++;
            }
            st.push(num[i]);
        }
        while(r < k && !st.empty()){
            st.pop();
            r++;
        }
        string ans = "";
        if((num.size() == k) || st.size() < 1) return "0";
        while(!st.empty()){
            ans += st.top(); 
            st.pop();
        }
        while(ans.size() > 1 && ans[ans.size()-1] == '0') ans.pop_back();
        reverse(ans.begin(), ans.end());
        return ans;
    }
};