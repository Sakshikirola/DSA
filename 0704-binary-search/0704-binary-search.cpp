class Solution {
public:
    int search(vector<int>& nums, int target) {
        int st=0 , end = nums.size()-1;
        while( st<= end){
            int mid = st + (end-st)/2 ; 
            if( target > nums[mid]){
                st = mid +1;
            }
            else if(target < nums[mid]){
                end = mid-1;
            }
            else{
                return mid;
            }
        }
        return -1;
    }
};