class Solution {
public:
    int findMaxVal(int n, vector<vector<int>>& restrictions, vector<int>& diff) {
        //int n = restrictions.size();
        vector<int> a(n, INT_MAX);

        for(auto &res : restrictions){
            a[res[0]] = min(res[1], a[res[0]]);
        }

        for(int i = n-2; i >= 0; --i){
            a[i] = min((long long)a[i], (long long)a[i+1]+diff[i]);
        }
        a[0] = 0;
        for(int i = 1; i < n; ++i){
            a[i] = min(a[i], a[i-1]+diff[i-1]);
        }
        return *max_element(a.begin(), a.end());
    }
};