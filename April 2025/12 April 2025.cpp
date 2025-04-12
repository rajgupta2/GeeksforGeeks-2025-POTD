//flood fill algorithm
class Solution {
    public:
      vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                    int newColor) {
          // Code here
          if (image[sr][sc] == newColor) {
              return image;
          }
          vector<vector<int>> copy(image);
          int n=copy.size();
          int m=copy[0].size();
          int originalColor=image[sr][sc];
          queue<pair<int,int>> q;
          q.push({sr,sc});
          copy[sr][sc]=newColor;
              int dr[]={-1,0,1,0};
              int dc[]={0,1,0,-1};
          while(!q.empty()){
              auto a=q.front();
              q.pop();
              for(int i=0;i<4;i++){
                  int nrow=a.first + dr[i];
                  int ncol=a.second + dc[i];
                  if(nrow>=0 && nrow<n && ncol>=0 &&  ncol<m && copy[nrow][ncol]==originalColor){
                      copy[nrow][ncol]=newColor;
                      q.push({nrow,ncol});
                  }
              }

          }
          return copy;
      }
  };