class Solution {
private:
   bool bfs(int row, int col, vector<vector<int>>&vis, vector<vector<int>>& grid){
     int n = grid.size();
     int m = grid[0].size();
     queue<pair<int,int>>q;
     q.push({row,col});
     vis[row][col] = 1;
     int drow[4] = {-1, 0, 1, 0};
     int dcol[4] = {0, -1, 0, 1};

     bool isclosed = true;
     while(!q.empty()){
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        if (r == 0 || c == 0 || r == n-1 || c == m-1) {
                isclosed = false;
        }

        for(int k=0; k<4; k++){
            int nrow = r + drow[k];
            int ncol = c + dcol[k];
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                    grid[nrow][ncol] == 0 && vis[nrow][ncol] == 0) {
                    vis[nrow][ncol] = 1;
                    q.push({nrow, ncol});
            } 
        }
     }
     return isclosed;
   }

public:
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int count = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 0 && vis[i][j] == 0){
                   if (bfs(i, j, vis, grid)) {
                        count++;
                    }
                }
            }
        }
        return count;
    }
};