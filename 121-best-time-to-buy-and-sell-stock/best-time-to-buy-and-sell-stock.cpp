class Solution {
    int solve(int idx , int buy , int count , vector<int>&prices,vector<vector<vector<int>>>&dp){
        int n = prices.size();
        if(idx>=n){
            return 0;
        }
        if(count==1){
            return 0;
        }
        if(dp[idx][buy][count]!=-1){
            return dp[idx][buy][count];
        }
        int take = 0;
        if(buy==1){
            take = solve(1+idx , 0 , count , prices,dp)-prices[idx];
        }
        else{
            take = solve(idx+1 , 0 , 1 , prices,dp )+prices[idx];
        }
        int ntake = solve(idx+1 , buy , count , prices,dp);
        return dp[idx][buy][count]=max(take , ntake);
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(2,-1)));
        return solve(0,1,0,prices,dp);
    }
};