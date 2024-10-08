class Solution {
    private:
     int solve(int idx , vector<int>&cost,vector<int> &dp){
         if(idx==0){
             return 0;
         }
         if(idx==1){
             return 0;
         }
         if(dp[idx]!=-1){
             return dp[idx];
         }
         int one = solve(idx-1 , cost,dp)+cost[idx-1];
         int two = solve(idx-2 , cost,dp)+cost[idx-2];
         return dp[idx]=min(one , two);
     }
public:
    
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+1,-1);
        return solve(n,cost,dp);
        // int n = cost.size();
        // vector<int> dp(n);
        // dp[0] = cost[0];
        // dp[1] = cost[1];
        // for(int i=3;i<n;i++){
        //     dp[i] = min(dp[i-1] , dp[i-2])+cost[i];
        // }
        // return dp[n-1];
    }
};