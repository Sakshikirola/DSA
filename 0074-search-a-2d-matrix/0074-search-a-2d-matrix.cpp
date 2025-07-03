class Solution {
public:
    bool searchInRow(vector<vector<int>>& mat, int target, int MR){
        int n = mat[0].size();
        int st = 0 , end = n-1;
        while(st<=end){
            int mid = st + ( end-st)/2 ;
            if(target == mat[MR][mid]){
                return true;
            }
            else if(target > mat[MR][mid]){
                st = mid+1 ;
            }
            else{
                end = mid-1;
            }
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int m = mat.size() , n = mat[0].size();
        int SR = 0 , ER = m-1;
        while(SR<=ER){
            int MR = SR + (ER-SR)/2 ;
            if( target >= mat[MR][0] && target <= mat[MR][n-1]){
                return searchInRow(mat , target , MR);
            }
            else if( target >= mat[MR][n-1]){
               SR = MR + 1;
            }
            else{
               ER = MR - 1 ;
            }
        }
        return false;
    }
};