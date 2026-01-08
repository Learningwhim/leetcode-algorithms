class MinStack {
public:
    stack<pair<int, long long>> st;
    int minm;
    MinStack() {
        minm = INT_MAX;
    }
    
    void push(int val) {
        st.push({val, min(minm, val)});
        minm = min(minm, val);
    }
    
    void pop() {
        st.pop();
        if(!st.empty()) minm = st.top().second;
        else minm = INT_MAX;
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */