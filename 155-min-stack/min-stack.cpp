class MinStack {
    stack<long> st;
    long minElement;
public:
    MinStack() {
        minElement = INT_MAX;
    }
    
    void push(long val) {
        if (st.empty()) {
            st.push(val);
            minElement = val;
        } else {
            if (val < minElement) {
                long diff = 2 * val - minElement;
                st.push(diff);
                minElement = val;
            } else {
                st.push(val);
            }
        }
    }
    
    void pop() {
        long diff = st.top();
        if (diff < minElement) {
            minElement = 2 * minElement - diff;
        }
        st.pop();        
    }
    
    int top() {
        long diff = st.top();
        if (diff < minElement) {
            return minElement;
        }
        return diff;
    }
    
    int getMin() {
        return minElement;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * long param_3 = obj->top();
 * long param_4 = obj->getMin();
 */