class Solution {
public:
    int maxArea(vector<int>& h) {
        int maxa = 0;
        int n = h.size();
        int i = 0, j = n-1;
        while(i < j){
            maxa = max(maxa, min(h[i],h[j])*(j-i));
            if(h[i] < h[j]) i++;
            else j--;
        }
        return maxa;
    }
};