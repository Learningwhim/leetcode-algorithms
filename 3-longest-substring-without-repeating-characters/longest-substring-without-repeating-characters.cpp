class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        int n = s.size();
        int l = 0, r = 0;
        int ans = 0;
        while(r < n){
            if(mp.find(s[r]) == mp.end()){
                mp[s[r]] = r;
                ans = max(r-l+1, ans);
            }else{
                ans = max(ans, r-l);
                int newi = mp[s[r]]+1;
                for(int i = l; i < newi; ++i){
                    mp.erase(s[i]);
                }
                l = newi; 
                mp[s[r]] = r;
            }
            r++;
        }
        return ans;
    }
};