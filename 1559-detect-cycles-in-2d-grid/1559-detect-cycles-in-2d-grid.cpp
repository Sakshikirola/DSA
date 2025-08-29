class Solution {
public:
    bool detect(int row, int col, vector<vector<int>>& vis, vector<vector<char>>& grid){ 
        int n = grid.size();
        int m = grid[0].size();
        char original = grid[row][col];
        queue<pair<pair<int,int>, pair<int,int>>> q; 
        q.push({{row,col}  ,{-1,-1}});
        vis[row][col] = 1;
        int drow[4] = {-1,0,1,0};
        int dcol[4] = {0,1,0,-1};

        while(!q.empty()){
            auto node = q.front();
            q.pop();
            int r = node.first.first;
            int c = node.first.second;
            int pr = node.second.first;
            int pc = node.second.second;

            for(int k=0; k<4; k++){
                int nrow = r + drow[k];
                int ncol = c + dcol[k];
                
               if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol] == original){
                    if(!vis[nrow][ncol]){
                        vis[nrow][ncol] = 1;
                        q.push({{nrow, ncol}, {r, c}});
                    } 
                    else if (!(nrow == pr && ncol == pc)) {
                        return true;
                    }
               }
            }
        }
        return false;
    }

    bool containsCycle(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>>vis(n, vector<int>(m,0));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!vis[i][j]){
                    if(detect(i,j,vis,grid)) return true;
                }
            }
        }
        return false;
    }
};