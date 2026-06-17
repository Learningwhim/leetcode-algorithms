class Solution {
public:
    vector<vector<vector<int>>> dp;

    int maxProfit(vector<int>& price) {
        int n = price.size();
        int cost = 0, mini = price[0];
        for(int i = 1; i < n; ++i){
            int profit = price[i]-mini;
            mini = min(mini, price[i]);
            cost = max(cost, profit);
        }
        return cost;
    }
};