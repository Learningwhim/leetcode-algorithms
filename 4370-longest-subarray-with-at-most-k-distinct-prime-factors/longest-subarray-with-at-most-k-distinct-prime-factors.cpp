class Solution {
public:
    
    int longestSubarray(vector<int>& nums, int k) {
        int maxe = *max_element(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> spf(maxe+1);
        for(int i = 2; i <= maxe; ++i){
            if(spf[i] == 0){
                for(int j = i; j <= maxe; j +=i){
                    spf[j] = i;
                }
            }
        }
        vector<vector<int>> primeFactors(n);
        for(int i = 0; i < n; ++i){
            int num = nums[i];
            while(num > 1){
                int p = spf[num];
                primeFactors[i].push_back(p);
                while(num%p == 0) num = num/p;
            }
        }

        unordered_map<int, int> mp;
        int l = 0, distinct = 0, maxLen = 0;
        for(int r = 0; r < n; ++r){
            for(auto p : primeFactors[r]){
                if(mp[p] == 0) distinct++;
                mp[p]++;
            }

            while(distinct > k){
                for(auto p : primeFactors[l]){
                    mp[p]--;
                    if(mp[p] < 1) distinct--;
                }

                l++;
            }
            maxLen = max(maxLen, r-l+1);
        }

        return maxLen;
        
    }
};