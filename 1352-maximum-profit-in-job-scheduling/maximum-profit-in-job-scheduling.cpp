class Solution {
    // int solve(int idx ,int prev , vector<pair<int, pair<int , int>>> &arr,vector<vector<int>>&dp ){
    //     int n = arr.size();
    //     if(idx==n){
    //         return 0;
    //     }
    //     if(dp[idx][prev+1] != -1){
    //         return dp[idx][prev+1];
    //     }
    //     auto it = arr[idx];
    //     int start = it.first;
    //     int end = it.second.first;
    //     int profit = it.second.second;
    //     int take = 0;
    //     if(prev==-1 || start>=arr[prev].second.first){
    //          take = profit+solve(idx+1 ,idx , arr,dp);
    //     }
    //     int ntake = solve(idx+1 , prev , arr,dp);
    //     return dp[idx][prev+1] = max(take, ntake);
        
    // }
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        //  int n = startTime.size();
        //  vector<pair<int, pair<int , int>>> arr;
        //  for(int i=0;i<n;i++){
        //     arr.push_back({startTime[i],{endTime[i] , profit[i]}});
        //  }
        //  vector<vector<int>>dp(n+1  , vector<int>(n+1 , -1));
        //  sort(arr.begin() , arr.end());
        //  return solve(0,-1,arr,dp);
        
         // we have used take , nottake logic which gave TLE => we used lowerbound logic to 
         // find the next index 
          int n = startTime.size();
        vector<pair<int, pair<int, int>>> arr;
        for (int i = 0; i < n; i++) {
            arr.push_back({startTime[i], {endTime[i], profit[i]}});
        }
        sort(arr.begin(), arr.end());
        vector<int> dp(n, -1);
        return solve(0, arr, dp);
    }
    int solve(int idx, vector<pair<int, pair<int, int>>> &arr, vector<int> &dp) {
        int n = arr.size();
        if(idx == n){
            return 0;
        }
        if(dp[idx] != -1){
            return dp[idx];
        }
        auto it = arr[idx];
        int start = it.first;
        int end = it.second.first;
        int profit = it.second.second;
        int nextIdx = lower_bound(arr.begin(), arr.end(), make_pair(end, make_pair(0, 0))) - arr.begin();
        int take = profit;
        if (nextIdx < n) {
            take += solve(nextIdx, arr, dp);
        }
        int ntake = solve(idx + 1, arr, dp);
        return dp[idx] = max(take, ntake);
    }
};