class Solution {
    private:
    int solve(int i, int prev ,vector<int>&a , vector<vector<int>>&dp){
        int n = a.size();
        if(i==n)
         return 0;
        if(dp[i][prev+1]!=-1) 
         return dp[i][prev+1]; 
     
         int tk=0;
        if(prev==-1 || a[prev]<a[i])
          tk = 1+solve(i+1 , i, a, dp);
        int ntk = solve(i+1 ,prev,a,dp);
        return dp[i][prev+1] = max(tk,ntk);    
 }
public:
    int lengthOfLIS(vector<int>& a) {
      /*  int n = a.size();
        int prev =-1;
         vector<vector<int>> dp(n,vector<int>(n+1,-1));
         return solve(0,-1,a,dp); */
           

        /* note : ways to do cordinte shift 
        1) do modification in loops see knapsack question , it involes changes in 
           caomparision , and returning in dp array 
        2) when modification in loops is not possible , like in this question 
           do changes in  storing the values */
        int n = a.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        for(int i=n-1;i>=0;i--){
            for(int prev = i-1;prev>=-1;prev--){
                 int tk=0;
                if(prev==-1 || a[prev]<a[i])
                   tk = 1+dp[i+1][i+1]; //    solve(i+1 , i, a, dp);
                int ntk = dp[i+1][prev+1]; // solve(i+1 ,prev,a,dp);
                dp[i][prev+1] = max(tk,ntk); 
            }
        }
      

      return dp[0][-1+1];
    }
   
};