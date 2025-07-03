class Solution {
public:
    void printSubsets(vector<int>&nums , vector<int>&ans , int i , vector<vector<int>>&allsubsets){
        if( i == nums.size()){
            allsubsets.push_back({ans}); 
            return;
        }

        ans.push_back(nums[i]);
        printSubsets(nums , ans , i+1 , allsubsets);
        ans.pop_back();

        int idx = i+1;
        while(idx<nums.size() && nums[idx] == nums[idx-1]) idx++;

        printSubsets(nums , ans , idx , allsubsets);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>allsubsets ;
        vector<int>ans ;
        printSubsets(nums,ans,0,allsubsets);
        return allsubsets ;
    }
};