class Solution {
public:
    bool isSameAfterReversals(int num) {
        int rev = 0;
        int secrev = 0;
        if(num==0){
            return true ; 
        }
        return num % 10 != 0;
        while(num!=0){
            int dig = num%10;
            rev = rev*10 + dig;
            num = num/10 ;
        }
        while(rev!=0){
            int dig = rev %10 ;
            secrev = secrev *10 + dig;
            rev = rev /10;
        }
        return secrev; 
    }
};