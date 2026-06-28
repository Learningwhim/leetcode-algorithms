class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int n = arr.size();
        
        sort(arr.begin(), arr.end());
        arr[0] = 1;
        for(int i = 1; i < n; ++i){
            if(arr[i]-arr[i-1] <= 1) continue;
            arr[i] = arr[i-1]+1;
        }
        int max = arr[n-1];
        return min(max,(int)arr.size());
    }
};