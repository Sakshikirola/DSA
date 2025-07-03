class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int sum = 0;
        for(int i =0 ; i<mat.size() ;i++){
                sum +=  mat[i][i]; // primary diagonal
           if(i!= mat.size()-i-1){ 
            sum += mat[i][mat.size()-i-1]; // secondary diagonal 
           }
        }
        return sum;
    }
};