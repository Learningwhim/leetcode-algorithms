class Solution {
public:
    unordered_map<char, int> vis;
    int check(char s){
        if(s >= 'a' && s <= 'z' && !vis[s]){
            vis[s] = 1;
            return 1;
        }
        else if(s >= 'A' && s <= 'Z' && !vis[s]){
            vis[s] = 1;
            return 2;
        }
        else if(s >= '0' &&  s <= '9' && !vis[s]){
            vis[s] = 1;
            return 3;
        }else if((s == '!' || s == '@' || s== '#' || s== '$')&& !vis[s]){
            vis[s] = 1;
            return 5;
        }
        return 0;
    }
    int passwordStrength(string password) {
        int sum = 0;
        for(char c : password){
            sum += check(c);
        }
        return sum;
    }
};