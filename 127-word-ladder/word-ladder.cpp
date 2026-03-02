class Solution {
public:
    
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> s;
        int ans = 0;
        for(auto word : wordList) s.insert(word);
        queue<string> q;
        string gen;
        q.push(beginWord);
        while(!q.empty()){
            int sz = q.size();
            ans++;

            for(int k = 0; k < sz; ++k){
                string curr = q.front(); q.pop();
                gen = curr;
                if(gen == endWord) break;
                for(int i = 0; i < curr.size(); ++i){
                    for(int j = 0; j < 26; ++j){
                        string gen = curr;
                        gen[i] = 'a' + j;
                        if(gen != curr && s.find(gen) != s.end()) {
                            q.push(gen);
                            s.erase(gen);
                        }
                    }
                }
            }
            if(gen == endWord) break;
        }
        if(gen == endWord) return ans;
        return 0;
    }
};