class Solution {
public:
    bool isAlphanum(char ch){
        return isalnum(ch);
    }
    bool isPalindrome(string s) {
        int st=0 , end = s.length()-1;
        while(st<end){
            if(!isAlphanum(s[st])){
                st++ ; continue;
            }
            if(!isAlphanum(s[end])){
                end-- ; continue;
            }
            if(tolower(s[st])!= tolower(s[end])){
                return false;
            }
            st++ , end--;
        }
        return true ;
    }
};