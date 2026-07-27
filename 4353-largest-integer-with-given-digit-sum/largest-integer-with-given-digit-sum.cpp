class Solution {
public:
    
    int largestInteger(int n, int s) {
        int currmax = 9;
        long long ans = 0;
        string st = "";
        if (s > 9 * n) return -1;
        while(s > 0 && n > 0){
            if(currmax < 0) return -1;
            if(currmax <= s){
                st += (char)'0'+currmax;
                s -= currmax;
                n--;
            }else currmax--;
        }
        while (n > 0) {
            st.push_back('0');
            n--;
        }
        ans = stoll(st);
        return ans;
    }
};