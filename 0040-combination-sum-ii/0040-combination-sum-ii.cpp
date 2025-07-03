class Solution {
public:
   void getAllcombination(vector<int>& arr,int idx, int tar, vector<vector<int>>&ans , vector<int>combin){
    if(tar==0){
        ans.push_back(combin);
        return;
    }

    for(int i=idx ; i<arr.size(); i++){
        if(i>idx && arr[i] == arr[i-1]) continue;
        if(arr[i]>tar) break;

    combin.push_back( arr[i] );
    getAllcombination(arr, i+1, tar - arr[i], ans, combin);//single choice
    combin.pop_back();
    }
   }

    vector<vector<int>> combinationSum2(vector<int>& arr, int tar) {
        vector<vector<int>>ans;
        vector<int>combin;
        sort(arr.begin(), arr.end());
        getAllcombination(arr,0,tar,ans,combin);
        return ans;
    }
};