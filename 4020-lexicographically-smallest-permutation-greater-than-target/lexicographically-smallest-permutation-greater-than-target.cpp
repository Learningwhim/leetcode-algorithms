class Solution {
public:
    string getMinString(const vector<int>& cnt){
        string res;
        for(int i = 0; i < 26; ++i){
                res.append(cnt[i],'a'+i);
        }
        return res;
    }
    string getMaxString(const vector<int>& cnt){
        string res;
        for(int i = 25; i >= 0; --i){
                res.append(cnt[i], 'a'+i);
            
        }
        return res;
    }
    bool canFormGreater(vector<int> &cnt, string target, int start){
        string maxs = getMaxString(cnt);
        string suffix = target.substr(start);
        return maxs > suffix;
    }
    string lexGreaterPermutation(string s, string target) {
        int n = s.size();
        vector<int> cnt(26, 0);
        for(int i = 0; i < n; ++i) cnt[s[i]-'a']++;
        string res;
        for(int i = 0; i < n; ++i){
            int tg = target[i]-'a';
            if(cnt[tg] > 0){
                cnt[tg]--;
                if(canFormGreater(cnt, target, i+1)){
                    res.push_back(target[i]);
                    continue;
                }

                cnt[tg]++;
            }
            for(int j = tg+1; j < 26; ++j){
                if(cnt[j] > 0){
                    cnt[j]--;
                    res.push_back('a'+j);

                    res += getMinString(cnt);
                    return res;
                }
            }
            return "";
        }

    
        return "";
    }
};