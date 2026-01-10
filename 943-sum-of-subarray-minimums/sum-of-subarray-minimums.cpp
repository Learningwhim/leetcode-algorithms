class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> pse(n, -1);
        vector<int> nse(n, n);
        long long  sum = 0;
        stack<int> st;
        for(int i = 0; i < n; ++i){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            if(!st.empty()) pse[i] = st.top();
            st.push(i);
        }
        st = stack<int>();
        for(int i = n-1; i >= 0; --i){
            while(!st.empty() && arr[st.top()] > arr[i]){
                st.pop();
            }
            if(!st.empty()) nse[i] = st.top();
            st.push(i);
        }
        long long m = 1e9+7;
        for(int i = 0; i < n; ++i){
            long long left = i-pse[i];
            long long right = nse[i]-i;
            sum = (sum%m + ((1ll*arr[i]*left%m)%m*right%m)%m)%m;
        }
        return sum;
    }
};