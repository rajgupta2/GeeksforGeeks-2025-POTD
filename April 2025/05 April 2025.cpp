//Find the number of islands
class Solution {
  public:
    void dfs(int r,int j,vector<vector<char>>& grid,vector<vector<int>>& vis){
        vis[r][j]=1;
        int n=grid.size();
        int m=grid[0].size();
        for(int dr=-1;dr<=1;dr++){
            for(int dc=-1;dc<=1;dc++){
                int nrow=r+dr;
                int ncol=j+dc;
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]=='L' && vis[nrow][ncol]==0){
                    dfs(nrow,ncol,grid,vis);
                }
            }
        }
    }
    int countIslands(vector<vector<char>>& grid) {
        // Code here
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]=='L'){
                    dfs(i,j,grid,vis);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};