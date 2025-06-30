class MinStack {
    private Stack<Long> st = null;
    private long minElement;
    public MinStack() {
        st = new Stack<>();
        minElement = Long.MAX_VALUE;
    }
    
    public void push(int val) {
        if (st.isEmpty()) {
            st.push((long)val);
            minElement = val;
        } else {
            if (val < minElement) {
                long diff = 2L * val - minElement;
                st.push(diff);
                minElement = val;
            } else {
                st.push((long)val);
            }
        }
    }
    
    public void pop() {
        long diff = st.peek();
        if (diff < minElement) {
            minElement = 2L * minElement - diff;
        }
        st.pop();
    }
    
    public int top() {
        long diff = st.peek();
        if (diff < minElement) {
            return (int)minElement;
        }
        return (int)diff;
    }
    
    public int getMin() {
        return (int)minElement;
    }
}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(val);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */