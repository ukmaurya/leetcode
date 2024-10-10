class Solution {
  /*  private:
    int solve(int i , int j , vector<vector<int>>& triangle , vector<vector<int >> &dp){
        int n = triangle.size();
        int m = triangle[n-1].size();
         if(i== n-1){
             return  triangle[i][j];
         }
         if(dp[i][j]!=-1) return dp[i][j];
         int down = triangle[i][j];
         if(i+1<n)
            down = solve(i+1 , j,triangle ,dp ) + triangle[i][j];
         int downr = triangle[i][j];
         if(i+1<n && j+1 < m)
           downr =  solve(i+1 ,j+1 , triangle , dp )+ triangle[i][j];
         return dp[i][j] = min(down , downr);
    } */
public:
    int minimumTotal(vector<vector<int>>& triangle) {
         int n = triangle.size();
         int m = triangle[n-1].size();
         vector<vector<int >> dp(n,vector<int>(m,0));
         for(int i=0;i<m;i++){
             dp[n-1][i] = triangle[n-1][i];
         }
         for(int i = n-2 ;i>=0;i--){
             int k= triangle[i].size();
             for(int j= 0;j<k;j++){
                 int down = INT_MAX;
                 if(i+1<n)
                   down = dp[i+1][j] + triangle[i][j];
                 int downr = INT_MAX;
                 if(i+1<n && j+1 < m)
                    downr =  dp[i+1][j+1]+ triangle[i][j];
                 dp[i][j] = min(down , downr);
             }
         }
         return dp[0][0]; 

         // space optimisation 

        //  int n = triangle.size();
        //  // exception case 
        //  if(n==1 ){
        //      return triangle[0][0];
        //  }
        //  vector<int > down(n);
        //  vector<int > up(n);
        //  for(int i=0;i<n;i++){
        //      down[i] = triangle[n-1][i];
        //  }
        //  for(int i = n-2 ;i>=0;i--){
        //      int k= triangle[i].size();
        //      for(int j= 0;j<k;j++){
                
                 
        //            int dow = down[j]+ triangle[i][j];
                 
                
        //             int downr =  down[j+1]+ triangle[i][j];
        //          up[j] = min(dow , downr);
        //      }
        //      down = up ; // assigning the vector 
        //  }
        //  return up[0];
    }
};