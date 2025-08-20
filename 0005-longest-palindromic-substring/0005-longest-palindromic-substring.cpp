class Solution {
public:
    void check(const string&s, int left, int right, int &start, int &maxlen){
        int n=s.size();
        while(left>=0 && right<n && s[left] == s[right]){
            if(right-left+1 > maxlen){
                maxlen = right - left + 1;
                start = left;
            }
            left--;
            right++;
        }
    }

    string longestPalindrome(string s) {
        if(s.size() <= 1) return s;
        int start = 0, maxlen = 1;
        int n = s.size();

        for(int i=0; i<n; i++){
            check(s,i,i,start,maxlen);
            check(s,i,i+1,start,maxlen);
        }
        return s.substr(start,maxlen);
    }
};