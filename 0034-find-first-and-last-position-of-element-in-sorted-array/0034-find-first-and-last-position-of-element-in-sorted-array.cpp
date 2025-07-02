class Solution {
public:
        int findstart(vector<int>&nums , int target){
            int st=0 , end = nums.size()-1 , result =-1 ;
            while(st<=end){
                int mid = st + ( end-st)/2 ;
                if(nums[mid] == target ){
                    result = mid;
                    end = mid-1 ;
                }
                else if(nums[mid]<target){
                    st = mid+1 ;
                }
                else{
                    end = mid-1;
                }
            }
            return result ;
        }

         int findsec(vector<int>&nums , int target){
            int st=0 , end = nums.size()-1 , result = -1 ;
            while(st<=end){
                int mid = st + ( end-st)/2 ;
                if(nums[mid] == target ){
                    result = mid;
                    st = mid+1 ;
                }
                else if(nums[mid]<target){
                    st = mid+1 ;
                }
                else{
                    end = mid-1;
                }
            }
            return result ;
        }
    vector<int>searchRange(vector<int>&nums , int target){
       return {findstart(nums,target) , findsec(nums,target)};
    }
};