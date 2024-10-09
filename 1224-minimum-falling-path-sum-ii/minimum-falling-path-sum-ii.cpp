class Solution {
    int solve(int row , int col ,vector<vector<int>>& grid,vector<vector<int>> &dp ){
        int n = grid.size();
        if(row==n-1){
          
               return grid[n-1][col];
         }
         if(dp[row][col]!=-1){
            return dp[row][col];
         }
       int ans = 1e9;
       for(int k=0;k<n;k++){
         int first = 1e9;
            if(k!=col)
               first = solve(row+1,k,grid,dp )+grid[row][col];
           ans = min(ans , first);
       }
     
        
       return dp[row][col] = ans;
        
    }
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int ans= 1e9;
        vector<vector<int>> dp(n+1 , vector<int>(n,-1));
        for(int i=0;i<n;i++){
            ans = min(ans , solve(0,i,grid ,dp));
        }
        return ans;
    }
};