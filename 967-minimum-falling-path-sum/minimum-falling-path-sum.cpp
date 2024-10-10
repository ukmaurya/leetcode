class Solution {
    private:
   long long  solve(int row , int col , vector<vector<int>>&matrix,vector<vector<int>>&dp){
        int n = matrix.size();
        if(row>=n || col>=n || row<0 ||col<0)
          return INT_MAX;
        if(row==n-1){
          return matrix[row][col];
        }  
        if(dp[row][col]!=-1)
           return dp[row][col];
       long long a = solve(row+1,col-1, matrix,dp)+matrix[row][col];
       long long  b = solve(row+1 ,col , matrix,dp)+matrix[row][col];
       long long  c = solve(row+1 , col+1 , matrix,dp)+matrix[row][col];
        return dp[row][col]= min(a , min(b,c));
    }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
       /* int n = matrix.size();
        long long  ans = INT_MAX;
        
        for(int i=0;i<n;i++){
            vector<vector<int>> dp(n,vector<int>(n,-1));
            ans = min(ans , solve(0,i,matrix,dp));
        }
        return ans ;
         */
         // TLE with memoization

        //  int n = matrix.size();
        //  vector<vector<int>> dp(n, vector<int>(n, 1e9));
        //  // initialization 
        //  for(int i=0;i<n;i++){
        //     dp[n-1][i]= matrix[n-1][i];
        //  }
        //  for(int row=n-2;row>=0;row--){
        //     for(int col=n-1;col>=0;col--){
                  
        //           long long  a = 1e9;
        //           if(col-1>=0)
        //             a = dp[row+1][col-1]+matrix[row][col];
        //           long long  b = 1e9;
        //             b = dp[row+1][col]+matrix[row][col];
        //           long long  c = 1e9;
        //           if(col+1<n)
        //             c = dp[row+1][col+1]+matrix[row][col];
                  
        //           dp[row][col]= min(a , min(b,c));
        //     }
        //  }

        // int ans = 1e9;
        // for(int i=0;i<n;i++){
        //     ans = min(ans , dp[0][i]);
        // }
        // return ans;

              int n = matrix.size();
              vector<int> last(n,0);
              for(int i=0;i<n;i++){
                 last[i]= matrix[n-1][i];
              }
         for(int row=n-2;row>=0;row--){
            vector<int> up(n,0);
            for(int col=n-1;col>=0;col--){
                long long  a = 1e9;
                  if(col-1>=0)
                    a = last[col-1]+matrix[row][col];
                  long long  b = 1e9;
                    b = last[col]+matrix[row][col];
                  long long  c = 1e9;
                  if(col+1<n)
                    c = last[col+1]+matrix[row][col];
                  
                  up[col]= min(a , min(b,c));
            }
            last = up;
         }

          int ans = 1e9;
        for(int i=0;i<n;i++){
            ans = min(ans , last[i]);
        }
        return ans;
    }
};