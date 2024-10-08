class Solution {
    int mod = 1e9+7;
    int solve(int idx , int prev , int n, vector<vector<int>>&dp){
        if(idx>n-1){
            return 1;
        }
        if(dp[idx][prev]!=-1){
            return dp[idx][prev]%mod;
        }
        int put = 0;
        if(prev==0){
            put = solve(idx+1 , 1 , n,dp)%mod;
        }
        int notput = solve(idx+1 , 0 , n,dp)%mod;
        return dp[idx][prev]=(put+notput)%mod;
        
    }
public:
    int countHousePlacements(int n) {
        vector<vector<int>> dp(n+1 , vector<int>(2 , -1));
        int ans =  solve(0,0 ,n,dp); // prev=0 means  prev index not filled , 1 means filled 
        return (ans*1LL*ans)%mod;
        
        
        
        
    }
};