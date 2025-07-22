class Solution {
public:
    bool isBalanced(string num) {
        if(num.empty()) return false;
        int i=0,n = num.size();
        int odd=0 , even=0;
        while(i<n){
            int digit = num[i] - '0';
           if(i%2 == 0){
            even += digit;
           }else{
            odd += digit;
           }
           i++;
        }
        
        return odd == even;
    }
};