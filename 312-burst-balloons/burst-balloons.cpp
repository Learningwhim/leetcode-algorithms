class Solution {
public:
    vector<vector<int>> dp;
    int f(int i, int j, vector<int> &a){
        if(i > j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int maxi = 0;
        for(int k = i; k <= j; ++k){
            int coins = a[i-1]*a[k]*a[j+1] + f(i, k-1, a) + f(k+1, j, a);
            maxi = max(maxi, coins);
        }
        return dp[i][j] = maxi;
    }
    int maxCoins(vector<int>& arr) {
        vector<int> nums;
        nums.push_back(1);
        for(int i = 0; i < arr.size(); ++i) nums.push_back(arr[i]);
        nums.push_back(1);
        
        int n = arr.size();
        dp.assign(n+2, vector<int> (n+2, 0));
        if(n==1)
        {
            return arr[0];
        }
        for(int i=n;i>=1;i--)
        {
            for(int j=1;j<=n;j++)
            {
                if(i>j)
                {
                    continue;
                }
                int maxi=0;
                for(int k=i;k<=j;k++)
                {
                    maxi=max(maxi,nums[i-1]*nums[k]*nums[j+1]+dp[i][k-1]+dp[k+1][j]);
                }
                dp[i][j]=maxi;
            }
        }
        return dp[1][n];
    }
};