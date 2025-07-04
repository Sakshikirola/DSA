class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int>freq;
        for(int c: nums){
          freq[c]++;
        }

        sort(nums.begin(),nums.end(),[&](int a, int b){
          if(freq[a]==freq[b]){
            return a>b;
          }
          return freq[a] < freq[b] ;
        });
        return nums;
    }
};