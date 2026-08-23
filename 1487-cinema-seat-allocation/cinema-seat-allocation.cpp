class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        int left = 0b11110000;
        int middle = 0b11000011;
        int right = 0b00001111;
        unordered_map<int,int> occ;
        for(const vector<int> &seat : reservedSeats){
            if(seat[1] >= 2 && seat[1] <=9){
                occ[seat[0]] |= (1 << (seat[1]-2));
            }
        }
        int ans = 0;
        for(auto &[row, bitmask]: occ){
            bool l = (bitmask|left) == left;
            bool r = (bitmask|right) == right;
            bool m = (bitmask|middle) == middle;
            if(l && r) ans+= 2;
            else if(l || r || m) ans += 1;
        }
        ans += (n-occ.size())*2;
        return ans;
    }
};