class Solution {
    private:
    int solve(string word1 , string word2 , int i , int j, vector<vector<int>> &dp ){
        if(i<0){ // insert all character of word2
            return j+1;
        }
        else if(j<0){ // delete all characters of word1
            return i+1;
        }
        if(dp[i][j]!= -1) return dp[i][j];
        
        if(word1[i]== word2[j]){
            return dp[i][j] = 0+solve(word1 , word2 , i-1,j-1,dp);
        }
        else{
            int replace = solve(word1 , word2 , i-1,j-1,dp);
            int del = solve(word1 , word2 , i-1,j,dp);
            int insert = solve(word1 , word2 , i, j-1,dp);// in insert donot decrement i take example a, ab 
            return dp[i][j] = min(1+replace , min(1+del, 1+insert));
        }
    }
public:
    int minDistance(string word1, string word2) {
        
        // int n = word1.size();
        // int m = word2.size();
       
        // vector<vector<int>> dp(n+1,vector<int>(m+1,0)); // n1+1 , m+1 due to shifting of index
        // // initialisation 
        // for(int j=0;j<=m;j++){
        //     dp[0][j] = j;
        // }
        // for(int i=0;i<=n;i++){
        //     dp[i][0] = i;
        // }
        // // step 2
        // for(int i=1;i<=n;i++){
        //     for(int j=1;j<=m;j++){
        //          if(word1[i-1]== word2[j-1]) // index shifted 
        //            dp[i][j] = 0+dp[i-1][j-1];
        //          else{
        //              int replace = dp[i-1][j-1];
        //              int del = dp[i-1][j];
        //              int insert = dp[i][j-1];  // in insert donot decrement i take example a, ab 
        //              dp[i][j] = min(1+replace , min(1+del, 1+insert));
        //             }
        //     }
        // }
        // return dp[n][m]; // due to shifting of index

        //  space optimisation 
         int n = word1.size();
        int m = word2.size();
        vector<int> prev(m+1 ,0);
         for(int j=0;j<=m;j++){
            prev[j] = j;
        }
        for(int i=1;i<=n;i++){
            vector<int> cur(m+1 ,0);
            cur[0] = i;
            for(int j=1;j<=m;j++){
                 if(word1[i-1]== word2[j-1]) // index shifted 
                     cur[j] = 0+prev[j-1];
                 else{
                     int replace = prev[j-1];
                     int del = prev[j];
                     int insert = cur[j-1];  // in insert donot decrement i take example a, ab 
                    cur[j] = min(1+replace , min(1+del, 1+insert));
                    }
            }
            prev = cur;
        }
         
        return prev[m];
    }
};