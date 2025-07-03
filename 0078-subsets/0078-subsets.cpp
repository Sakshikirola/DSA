class Solution {
public:
void allsubsets(vector<int> &nums , vector<int>&ans , int i ,  vector<vector<int>>&subsets){
    if( i == nums.size()){
         subsets.push_back({ans});
     return;
   }
    ans.push_back(nums[i]);//include
    allsubsets(nums,ans,i+1,subsets);
    ans.pop_back();
    allsubsets(nums,ans,i+1,subsets);//exclude
}
    vector<vector<int>> subsets(vector<int>& nums) {
       vector<vector<int>>subsets ;
       vector<int> ans;
       allsubsets(nums,ans,0,subsets) ;
       return subsets;
    }
};