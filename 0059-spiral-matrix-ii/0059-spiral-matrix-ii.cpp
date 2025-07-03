class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> mat(n, vector<int>(n, 0));
        int srow = 0 , erow = n-1 , scol = 0 , ecol = n-1 ;
        int val =1;
        while(srow <= erow && scol <= ecol){
            for(int j=scol ; j<=ecol ; j++ ){//top
              mat[srow][j] = val++;
            }
            
            for(int i = srow+1 ; i<= erow ;i++){// right
                mat[i][ecol] = val++;
            }

            for(int j = ecol-1 ; j>= scol ;j--){//bottom
                if(srow==erow){
                    break;
                }
                mat[erow][j] = val++;
            }

            for(int i = erow-1 ; i>= srow+1; i--){//left
                if(scol==ecol){
                    break;
                }
                mat[i][scol] = val++;
            }
            srow++ , erow-- , scol++ , ecol-- ;
        }
        return mat;
    }
};