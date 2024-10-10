class Solution {
    int solve(int r , int c , int tr , int tc, vector<vector<int>>& grid , vector<vector<int>>& vis , int empty ){
         int n = grid.size();
         int m = grid[0].size();
         if(r==tr && c==tc){
            if(empty==0)
              return 1;
            return 0; 
         }
         if(r>=n || r<0 ||c<0 ||c>=m ||vis[r][c]==1 )
           return 0;
         int ans =0;
         vis[r][c]=1;
         int dx[] = {0,1,0,-1};
         int dy[] = {1,0,-1,0};
         for(int k=0;k<4;k++){
            int row = r+dx[k];
            int col = c+dy[k];
            if(row>=0 &&row<n && col>=0 &&col<m && vis[row][col]==0 && grid[row][col] != -1 ){
                ans += solve(row ,col , tr,tc , grid,vis , empty-1);
            }
         }
        vis[r][c]=0;
        return ans;
    }
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int startRow = -1;
        int startCol =-1;
        int endRow = -1;
        int endCol = -1;
        int empty = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    startRow = i;
                    startCol = j;
                }
                else if(grid[i][j]==2){
                    endRow = i;
                    endCol = j;
                }
                else if(grid[i][j]==0){
                    empty++;
                }
            }
        }
         empty++;
        return solve(startRow , startCol , endRow , endCol , grid , vis,empty);
    }
};