class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> pse(n, -1);
        vector<int> nse(n, n);
        stack<int> st;
        for(int i = 0; i < n; ++i){
            while(!st.empty() && heights[st.top()] >= heights[i]) st.pop();
            if(!st.empty()) pse[i] = st.top();
            st.push(i);
        }
        st = stack<int> ();
        for(int i = n-1; i >= 0; --i){
            while(!st.empty() && heights[st.top()] > heights[i]) st.pop();
            if(!st.empty()) nse[i] = st.top();
            st.push(i);
        }
        long long area = 0;
        for(int i = 0; i < n; ++i){
            long long maxl = nse[i]-pse[i]-1;
            area = max(area, maxl*1ll*heights[i]);
        }
        return area;
    }
};