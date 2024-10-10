class Solution {
    private: 
    int solve(int i, int j ){
        if(i==0&& j==0)
         return 1;
        else if(i<0 || j<0) 
          return 0;
        int up =0;
        int right =0;
        up  = solve(i-1,j);
        right = solve(i,j-1);
        return up+right;   
    }
public:
    int uniquePaths(int m, int n) {
        //  return solve(n-1,m-1);

        // vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        //  dp[n-1][m-1]=1;
        //  for(int i=n-1;i>=0;i--){
        //     for(int j=m-1;j>=0;j--){
        //         if(i==n-1 &&j==m-1)
        //           continue;
        //         int right = dp[i][j+1];
        //         int left = dp[i+1][j];
        //         dp[i][j] = left+right;
        //     }
        //  }
        // return dp[0][0];
  
        // space optimisation 

         vector<int> last(m+1 ,0);
         last[m-1] =1;
         for(int i=n-1;i>=0;i--){
            vector<int> cur(m+1,0);
            for(int j=m-1;j>=0;j--){
                if(i==n-1 && j==m-1){
                    cur[j]=1;
                    continue;
                }
                int right = cur[j+1];
                int left = last[j];
                cur[j] = left+right;
            }
             last = cur;
         }           
       return last[0];

    }
};