class Solution {
public:
    int maxProfit(vector<int>& price) {
        int n = price.size();
        int mini = price[0], cost = 0;
        for(int i = 1; i < n; ++i){
            cost = max(cost ,price[i]-mini);
            mini = min(mini, price[i]);
        }
        return cost;
    }
};