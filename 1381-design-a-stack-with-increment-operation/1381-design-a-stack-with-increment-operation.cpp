class CustomStack {
    vector<int> st;
    int maxSize;
public:
    CustomStack(int maxSize) {
        this->maxSize = maxSize; 
    }
    
    void push(int x) {
        if (st.size() < maxSize) {
            st.push_back(x);
        }
    }
    
    int pop() {
        if (st.empty()) return -1;
        int val = st.back();
        st.pop_back();
        return val;
    }
    
    void increment(int k, int val) {
        int limit = min(k, (int)st.size());
        for (int i = 0; i < limit; i++) {
            st[i] += val;
        }
    }
};


/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */