class Solution {
    private:  
     int solve(int i, int j , vector<int>&cuts, vector<vector<int>>&dp){
         if(i>j){
             return 0;
         }
         if(dp[i][j]!= -1){
             return dp[i][j];
         }
         int cost = INT_MAX;
         for(int k=i;k<=j;k++){
             int left = solve(i,k-1 , cuts,dp);
             int right = solve(k+1, j, cuts,dp);
             cost = min(cost, (left+right)+cuts[j+1]-cuts[i-1]);
         }
         return dp[i][j] = cost;
     }
    
   
public:
    int minCost(int n, vector<int>& cuts) {
        
        cuts.insert(cuts.begin(), 0);
        cuts.push_back(n);
        sort(cuts.begin() , cuts.end());
        vector<vector<int>>dp(cuts.size(), vector<int>(cuts.size(),-1));
        return solve(1,cuts.size()-2,cuts,dp);
    }
};