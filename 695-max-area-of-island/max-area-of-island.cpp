class Solution {
    
    void solve(int r, int c , vector<vector<int>>&grid , vector<vector<bool>>&vis,int &ans){
         int n = grid.size();
         int m = grid[0].size();
         vis[r][c]=true;
         int dx[]={0,1,0,-1};
         int dy[]={1,0,-1,0};
         ans = ans+1;
     //   cout<<ans<<" "<<endl;
        for(int k=0;k<4;k++){
            int row = r+dx[k];
            int col = c+dy[k];
            if(row>=0&&row<n &&col>=0 &&col<m && vis[row][col]==false && grid[row][col]==1){
               solve(row,col,grid,vis,ans);
            }
        }
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        int maxi = 0;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && vis[i][j]==false){
                    int ans = 0;
                    solve(i,j,grid,vis,ans);
                    maxi =  max(ans , maxi);
                    
                }
            }
        }
        
        return maxi;
   
        
    }
};