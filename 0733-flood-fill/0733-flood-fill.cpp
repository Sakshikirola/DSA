class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
       int n = image.size();
       int m = image[0].size();
       int original = image[sr][sc];

       if(original == color) return image;
       queue<pair<int,int>> q;
       q.push({sr,sc});
       image[sr][sc] = color;

       int drow[4] = {-1,1,0,0};
       int dcol[4] = {0,0,-1,1};

       while(!q.empty()){
        auto[row , col] = q.front();
        q.pop();

        for(int k=0; k<4; k++){
            int nrow = row + drow[k];
            int ncol = col + dcol[k];

            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && image[nrow][ncol] == original){
              image[nrow][ncol] = color;
              q.push({nrow , ncol});
            }
        }
       }
      return image;
    }
};