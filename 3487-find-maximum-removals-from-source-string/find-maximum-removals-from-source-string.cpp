class Solution {
    int solve(int i , int j , string &source, string &pattern, unordered_map<int , int>&mp,vector<int>& t,vector<vector<int>> &dp){
        int n = source.size();
        int m = pattern.size();
         if(j==m){
            int ind = lower_bound(t.begin(), t.end(), i) - t.begin();
            return mp.size()-ind;
           
         }
         if(i==n){
            return -1e6;
         }
         if(dp[i][j] !=-1)
           return dp[i][j];
         int ans= INT_MIN;

         int remove = INT_MIN;
         if(mp.find(i)!=mp.end()){
            remove = 1+solve(i+1 , j, source , pattern , mp,t,dp);
         }
         int notremove = INT_MIN;
          if(source[i]== pattern[j]){
                notremove=solve(i+1 , j+1 , source , pattern , mp,t ,dp);
          }
          else{
               notremove = solve(i+1 , j , source , pattern , mp,t,dp);

          }
          ans = max(remove , notremove);
          return dp[i][j]= ans; 

}
public:
    int maxRemovals(string source, string pattern, vector<int>& targetIndices) {
          unordered_map<int, int > mp;
          int n = targetIndices.size();
          for(int i=0;i<n;i++){
            mp[targetIndices[i]]++;
          }
        int s = source.size();
        int p = pattern.size();
        vector<vector<int>> dp(s , vector<int>(p,-1));
        return solve(0,0,source , pattern , mp , targetIndices,dp);

    }
};