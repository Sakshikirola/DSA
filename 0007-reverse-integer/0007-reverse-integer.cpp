class Solution {
public:
    int reverse(int x) {
        int rev = 0;
        while(x!=0){
           int dig = x%10 ;
           if(rev >INT_MAX/10 || rev < INT_MIN/10){
              return 0;
           }
           rev = rev * 10 + dig;
           x = x/10;
        }
        return rev;
    }
};