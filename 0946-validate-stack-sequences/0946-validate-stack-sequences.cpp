class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) { 
        stack<int>s;
        int i=0; 
        for(int val:pushed){
            s.push(val);
            while(!s.empty() && s.top() == popped[i]){
                s.pop();
                i++;
            }
        }
        return s.empty(); 
    }
};