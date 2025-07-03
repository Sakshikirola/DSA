class MinStack {
public:
    stack<long long int>s;
    long long int minval;
    MinStack() {
        
    }
    
    void push(int val) {
        if(s.empty()){
            s.push(val);
            minval = val;
        }else{
           if(val<minval){
            s.push((long long)2*val - minval);
            minval = val;
           }else{
            s.push(val);
           }
        }
    }
    
    void pop() {
        if(s.top()<minval){
            minval = 2*minval - s.top();
        }
        s.pop();
    }
    
    int top() {
        if(s.top()<minval){
            return minval;
        }
        return s.top();
    }
    
    int getMin() {
        return minval;
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