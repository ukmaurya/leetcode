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
        int n = nums.size();
        vector<vector<int>>dp(n+1 , vector<int>(2,-1));
        bool first = false;
        return solve(0,nums, first,dp);
    }
};