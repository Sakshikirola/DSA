class Solution {
public:
    void generate(vector<string>&result, string& current, int open, int close, int n){
        if(current.length() == n*2){ // if string is complete
            result.push_back(current);
            return;
        }

        if(open<n){
            current.push_back('(');
            generate(result, current , open+1, close, n);
            current.pop_back();
        }

        if(close<open){
            current.push_back(')');
            generate(result, current , open, close+1, n); 
            current.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string>result ;
        string current = ""; 
        generate(result , current, 0, 0, n);
        return result;
    }
};