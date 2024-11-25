class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
            vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(m,0)));
         // initialisation 
         for(int i=0;i<m;i++){
             for(int j=0;j<m;j++){
                 if(i==j){
                     dp[n-1][i][j] = grid[n-1][i];
                 }
                 else{
                     dp[n-1][i][j] = grid[n-1][i]+grid[n-1][j];
                 }
             }
         }
         
         for(int row=n-2;row>=0;row--){
             for(int col1 =0;col1<m;col1++){
                 for(int col2=0;col2<m;col2++){
                     
                     int ans = 0;
                     for(int i=-1;i<=1;i++){
                         for(int j=-1;j<=1;j++){
                             
                             int c1 = col1 + i;
                             int c2 = col2 + j;
                             if(c1>=0 &&c1<m && c2>=0 &&c2<m){
                                 int temp =0;
                                 if(col1==col2){
                                     temp = dp[row+1][c1][c2]+grid[row][col2];
                                 }
                                 else{
                                     temp = dp[row+1][c1][c2] +grid[row][col1]+grid[row][col2];
                                 }
                        
                                 ans = max(ans , temp);
                                 
                             }
                             
                             
                         }
                     }
                     dp[row][col1][col2]=ans;
                     
                     
                 }
             }
         }
         
         
         return dp[0][0][m-1];   
    }
};