class Solution {
public:
    int countKthRoots(int l, int r, int k) {
        if(k == 1) return r-l+1;
        int res = 0, maxx = pow(r, 1.0/ k)+1;
        for(int i = 0; i < maxx; ++i){
            long long y = pow(i, k);
            if(l <= y && y <= r) res++;
        }
        return res;
    }
};