class Solution {
public:
    bool isvalid(vector<vector<int>>& grid, int r, int c, int n, int expval){
       if(r<0 || c<0 || r>=n || c>=n || grid[r][c] != expval){
        return false;
       }
       if(expval == n*n-1){
        return true;
       }

       //8 possible move
       int ans1 = isvalid(grid , r-2 , c+1 , n, expval+1);
       int ans2 = isvalid(grid , r-1 , c+2 , n, expval+1);
       int ans3 = isvalid(grid , r-2 , c-1 , n, expval+1);
       int ans4 = isvalid(grid , r-1 , c-2 , n, expval+1);
       int ans5 = isvalid(grid , r+2 , c+1 , n, expval+1);
       int ans6 = isvalid(grid , r+1 , c+2 , n, expval+1);
       int ans7 = isvalid(grid , r+2 , c-1 , n, expval+1);
       int ans8 = isvalid(grid , r+1 , c-2, n, expval+1);

       return ans1 || ans2 || ans3 || ans4 || ans5 || ans6 || ans7 || ans8;
    }
 
    bool checkValidGrid(vector<vector<int>>& grid) { 
        return isvalid(grid, 0, 0, grid.size(), 0);
    }
};