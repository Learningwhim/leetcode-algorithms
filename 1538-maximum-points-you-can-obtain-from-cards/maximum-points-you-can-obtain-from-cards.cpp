class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        
        int rsum = 0, lsum = accumulate(cardPoints.begin(), cardPoints.begin()+k, 0);
        int sum = lsum+rsum;
        for(int i = k-1, j = 0; i >= 0; --i, ++j){
            //cout<<lsum<<" "<<rsum<<" "<<sum<<endl;
            lsum -= cardPoints[i];
            rsum += cardPoints[n-1-j];
            sum = max(sum, lsum+rsum);
            
        }
        
        return sum;
    }
};