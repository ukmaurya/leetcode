class Solution {
    int solve(int row , int col ,vector<vector<int>>& matrix , vector<vector<int>>& vis, vector<vector<int>>&dp ){
          int n = matrix.size();
          int m= matrix[0].size();
          if(dp[row][col]!=-1)
            return dp[row][col];
         vis[row][col]=1;
         int dx[]={0,1,0,-1};
         int dy[]={1,0,-1,0};
         int maxi = 0;
         for(int k=0;k<4;k++){
              int r = row+dx[k];
              int c = col+dy[k];
              if(r>=0 &&r<n&&c>=0 &&c<m &&vis[r][c]!=1 && matrix[r][c]>matrix[row][col]){
                    maxi = max(maxi ,1+solve(r,c,matrix,vis,dp));
              }
         }
         vis[row][col]=0;
         return dp[row][col]=maxi;
    }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
            int n = matrix.size();
            int m= matrix[0].size();
            int ans = INT_MIN;
            vector<vector<int>>vis(n,vector<int>(m,0));
             vector<vector<int>>dp(n,vector<int>(m,-1));
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                       if(vis[i][j]!=1){
                         ans = max(ans,1+solve(i,j,matrix,vis,dp));
                       }
                       
                }
            }
            return ans;
    }
};