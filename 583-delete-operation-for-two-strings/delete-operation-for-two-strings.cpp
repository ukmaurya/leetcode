class Solution {
    int solve(int i, int j,string &word1 , string &word2){
        int n = word1.size();
        int m = word2.size();
        if(i==n && j== m){
            return 0;
        }
        if(i==n){
            return m-j;
        }
        else if(j==m){
            return n-i;
        }
        
        if(word1[i]==word2[j]){
            return solve(i+1 , j+1 , word1 , word2);
        }
        else{
            return 1+min(solve(i+1 ,j,word1 , word2) , solve(i,j+1 , word1 ,word2));
        }
        return 0;
    }
public:
    int minDistance(string word1, string word2) {
        // apprach 1 : n+m-lcs

        // approach 2 
       
       
        // return solve(0,0,word1 , word2);
        // int n = word1.size();
        // int m = word2.size();
        // vector<vector<int>>dp(n+1 , vector<int>(m+1 , 1e9));
        // // inititalisaton
        // dp[n][m]=0;
        // for(int j=0;j<m;j++){
        //    dp[n][j] = m-j;
        // }
        // for(int i=0;i<n;i++){
        //    dp[i][m] = n-i;
        // }

        // for(int i=n-1;i>=0;i--){
        //     for(int j=m-1;j>=0;j--){
        //         if(word1[i]==word2[j]){
        //             dp[i][j] = dp[i+1][j+1];
        //         }
        //         else{
        //             dp[i][j] = 1+min(dp[i+1][j] , dp[i][j+1]);
        //         }
        //     }
        // }

        // return dp[0][0];

        // space optimisation  care : here 2 side initialisation is there 
         int n = word1.size();
        int m = word2.size();
        vector<int> last(m+1 , 0);
        vector<int> right(n+1 , 0);
        for(int j=0;j<m;j++){
           last[j] = m-j;
        }
        for(int i=0;i<n;i++){
            right[i] = n-i;
        }
         for(int i=n-1;i>=0;i--){
            vector<int> cur(m+1 , 0);
            for(int j=m-1;j>=0;j--){
                if(word1[i]==word2[j]){
                    cur[j] = last[j+1];
                    if(j==m-1)
                      cur[j] = right[i+1];
                }
                else{
                    int temp =  cur[j+1];
                    if(j==m-1)
                      temp = right[i];
                    cur[j] = 1+min(last[j] , temp);
                   
                }
            }
            last = cur;
        }
        return last[0];

    }
};