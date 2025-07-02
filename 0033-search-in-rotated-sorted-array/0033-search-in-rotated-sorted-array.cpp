class Solution {
public:
    int search(vector<int>& A, int target) {
        int st=0 , end = A.size()-1 ; 
        while( st <= end){
            int mid = st + (end-st)/2 ;
            if( A[mid] == target){
                return mid;
            }

            if( A[st]<= A[mid] ){
                if( A[st] <= target && target <= A[mid]){
                    end = mid-1;
                }
                else{
                    st = mid+1;
                }
            }

            else{
                if( A[mid] <= target && target <= A[end]){
                    st = mid+1;
                }
                else{
                    end = mid -1;
                }
            }
        }
        return -1;
    } 
};