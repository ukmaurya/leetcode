class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        // int n = grid.size();
        // int m = grid[0].size();
        // vector<vector<int>>dp(n,vector<int>(m,0)); 
        // dp[n-1][m-1] = grid[n-1][m-1];  
        // for(int i=n-1;i>=0;i--){
        //     for(int j=m-1;j>=0 ;j--){
        //         if(i==n-1 && j==m-1){ // this condition will be used since intialising only one cell 
        //             continue;
        //         }
        //         int right=INT_MAX;
        //         if(j+1<m)
        //           right = dp[i][j+1]+grid[i][j];
        //         int down =INT_MAX;
        //         if(i+1<n)
        //            down = dp[i+1][j]+grid[i][j];
        //         dp[i][j] = min(right,down);   
        //     }
        // }
        // return dp[0][0]; // maximum path sum from 0,0 to n-1,m-1;


        int n = grid.size();
        int m = grid[0].size();
        vector<int> last(m,0);
        for(int i=n-1;i>=0;i--){
            vector<int> cur(m,0);
            for(int j=m-1;j>=0 ;j--){
                if(i==n-1 && j==m-1){ // this condition will be used since intialising only one cell            
                    cur[j]=grid[n-1][m-1];
                    continue;
                }
                int right=INT_MAX;
                if(j+1<m)
                  right = cur[j+1]+grid[i][j];
                int down =INT_MAX;
                if(i+1<n)
                   down = last[j]+grid[i][j];
                cur[j] = min(right,down);   
            }
            last = cur;
        }
        return last[0];

    }
};