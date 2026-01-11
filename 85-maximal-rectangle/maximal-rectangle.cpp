class Solution {
public:
    long long histogram(vector<int> h){
        int n = h.size();
        vector<int> pse(n, -1);
        vector<int> nse(n, n);
        stack<int> st;
        for(int i = 0; i < n; ++i){
            while(!st.empty() && h[st.top()] >= h[i]) st.pop();
            if(!st.empty()) pse[i] = st.top();
            st.push(i);
        }
        st = stack<int>();
        for(int i = n-1; i >= 0; i--){
            while(!st.empty() && h[st.top()] > h[i]) st.pop();
            if(!st.empty()) nse[i] = st.top();
            st.push(i);
        }
        long long sum = 0;
        for(int i = 0; i < n; ++i){
            int left = i-pse[i]-1;
            int right = nse[i]-i;
            int width = left+right;
            sum = max(sum, (1ll*width)*h[i]);
        }
        return sum;


    }
    int maximalRectangle(vector<vector<char>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<int> height(m, 0);
        int ans = 0;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if(mat[i][j] == '1') height[j]++;
                else height[j] = 0;
            }
            ans = max(ans, (int)histogram(height));
        }
        return ans;
        
    }
};