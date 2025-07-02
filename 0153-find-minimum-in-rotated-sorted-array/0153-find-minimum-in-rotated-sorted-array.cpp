class Solution {
public:
    int findMin(vector<int>& nums) {
        int st=0 , end = nums.size()-1;
        if(nums[st] <= nums[end]) return nums[st] ;
        while(st<=end){
            int mid = st + (end-st)/2 ;
            if(nums[mid]>nums[mid+1]){
                return nums[mid+1];
            }
            if(nums[mid-1]>nums[mid]){
                return nums[mid];
            }
           
            if(nums[mid]>=nums[st]){
                st = mid+1;
            }
            else{
                end = mid-1;
            }
        }
        return -1;
    }
};