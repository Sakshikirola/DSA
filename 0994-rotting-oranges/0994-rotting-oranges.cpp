class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<pair<int,int>,int>> q;
        vector<vector<int>> vis(n, vector<int>(m, 0)); 

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 2){
                    q.push({{i,j}, 0});
                    vis[i][j] = 2; 
                }
            }
        }

        int time = 0;
        int drow[4] = {-1,0,1,0};
        int dcol[4] = {0,1,0,-1};

        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            q.pop();
            time = max(time, t);

            for(int k=0; k<4; k++){
                int nrow = r + drow[k];
                int ncol = c + dcol[k];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m &&
                   grid[nrow][ncol] == 1 && vis[nrow][ncol] != 2){
                    
                    q.push({{nrow,ncol}, t+1});
                    vis[nrow][ncol] = 2;   
                }
            }
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1 && vis[i][j] != 2){
                    return -1; 
                }
            }
        }

        return time;
    }
};
