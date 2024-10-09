class Solution {
    int solve(int idx , vector<int>&nums, bool first,vector<vector<int>>&dp){
        int n = nums.size();
        if(idx>n-1){
            return 0;
        }
        if(idx==n-1){
            if(first == false){ // can take last if havent took first one 
                return nums[idx];
            }
            else{
                return 0;
            }
        }
        if(dp[idx][first]!=-1){
            return dp[idx][first];
        }
        int ntake = solve(idx+1 , nums , first,dp);
        if(idx==0){
            first = true;
        }
        int take = solve(idx+2 , nums,first,dp)+nums[idx];
        return dp[idx][first]= max(take , ntake);
       
    }
public:
    int rob(vector<int>& nums) {
        // applying second approach
        // int n = nums.size();
        // vector<vector<int>>dp(n+1 , vector<int>(2,-1));
        // bool first = false;
        // return solve(0,nums, first,dp);
        // Initialize the DP table
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));
        dp[n-1][0] = nums[n-1];
        for(int i=n-2;i>=0;i--){
            for(int j=0;j<2;j++){ // expressiong false and true using 1 and 0 
                 int ntake = dp[i+1][j]; //  solve(idx+1 , nums , first,dp);
                 int take = dp[i+2][j]+nums[i]; // solve(idx+2 , nums,first,dp)+nums[idx];
                if(i==0 && j==0){ // very imp condition
                    take = dp[i+1][j];
                }
                 dp[i][j]= max(take , ntake);
            }
        }
        return max(dp[0][0],dp[0][1]);
    }
};