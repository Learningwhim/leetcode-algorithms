class StockSpanner {
public:
    vector<int> arr;
    stack<int> st;
    StockSpanner() {
            arr = vector<int> ();
            st = stack<int> ();
    };
    
    int next(int price){
        int ans = 1;
            arr.push_back(price);
            while(!st.empty() && arr[st.top()] <= price) st.pop();
            if(!st.empty()) ans = arr.size()-st.top()-1;
            else ans = arr.size();
            st.push(arr.size()-1);
            return ans;
        }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */