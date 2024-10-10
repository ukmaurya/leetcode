class Solution {
    private:
       int solve(int i ,int j, vector<vector<int>>&dp,vector<vector<int>>& obstacleGrid){
             if(i==0 && j==0 && obstacleGrid[0][0]!=1) return 1;
             if(i<0 || j<0 )
               return 0;
             if(obstacleGrid[i][j]==1 || obstacleGrid[i][j]==1)
               return 0;  
             if(dp[i][j]!=-1) return dp[i][j];
             
             int ans1=0;
             ans1 = solve(i-1 ,j,dp,obstacleGrid);
             int ans2 = 0;
             ans2 = solve(i,j-1,dp , obstacleGrid);
             return dp[i][j] = ans1+ans2;    
             
       }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
            
            // int a = obstacleGrid.size();
            // int b = obstacleGrid[0].size();
            // if(obstacleGrid[a-1][b-1]==1) return 0;
            // vector<vector<int>> dp(a,vector<int>(b,-1));
            // return solve(a-1,b-1,dp , obstacleGrid);

            int a = obstacleGrid.size();
            int b = obstacleGrid[0].size();
            if(obstacleGrid[a-1][b-1]==1 || obstacleGrid[0][0]==1) return 0;
            vector<vector<int>> dp(a+1,vector<int>(b+1,0));
            dp[0][0]=1;
            for(int i=0;i<a;i++){
                for(int j=0;j<b;j++){
                    if((i==0 &&j==0) || obstacleGrid[i][j]==1){
                        continue;
                    }
                    int up = 0;
                    if(i-1>=0)
                      up = dp[i-1][j];

                    int left =0;
                    if(j-1>=0)
                      left = dp[i][j-1];
                    dp[i][j] = left + up;
                }
            }

        return dp[a-1][b-1];

    }
};