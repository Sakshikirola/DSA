class Solution {
private:
    void bfs(int row, int col,vector<vector<int>>&vis,vector<vector<int>>& grid){
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>>q;
        q.push({row,col});
        vis[row][col] = 1;
        int drow[4] = {-1, 0, 1, 0};
        int dcol[4] = {0, 1, 0, -1};
        
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for(int k=0; k<4; k++){
                int nrow = r + drow[k];
                int ncol = c + dcol[k];
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                    !vis[nrow][ncol] && grid[nrow][ncol] == 1) {
                    vis[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }
        }
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>vis(n, vector<int>(m,0));
        for (int i = 0; i < n; i++) {
            if (grid[i][0] == 1 && !vis[i][0]) bfs(i, 0, vis, grid);
            if (grid[i][m-1] == 1 && !vis[i][m-1]) bfs(i, m-1, vis, grid);
        }
        for (int j = 0; j < m; j++) {
            if (grid[0][j] == 1 && !vis[0][j]) bfs(0, j, vis, grid);
            if (grid[n-1][j] == 1 && !vis[n-1][j]) bfs(n-1, j, vis, grid);
        }

        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1 && !vis[i][j]) {
                    count++;
                }
            }
        }
        return count;
    }
};