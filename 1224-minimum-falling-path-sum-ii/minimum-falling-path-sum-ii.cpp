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
        // int n = grid.size();
        // int ans= 1e9;
        // vector<vector<int>> dp(n+1 , vector<int>(n,-1));
        // for(int i=0;i<n;i++){
        //     ans = min(ans , solve(0,i,grid ,dp));
        // }
        // return ans;
         int n = grid.size();
        vector<vector<int>> dp(n+1 , vector<int>(n+1,1e9));
         // initialisation 
         for(int j=0;j<n;j++){
            dp[n-1][j] = grid[n-1][j];
         }
        
          for(int i=n-2;i>=0;i--){
             for(int j=0;j<n;j++){
            int ans = 1e9;
            for(int k=n-1;k>=0;k--){
                 int first = 1e9;
                if(k!=j){
                    first =  dp[i+1][k]+grid[i][j];
                }
                ans = min(ans, first);
            }
            dp[i][j] = ans;
          }
          
         }
       
       int mini = INT_MAX;
       for(int i=0;i<n;i++){
         mini = min(mini , dp[0][i]);
       }
       return mini;
    }
};