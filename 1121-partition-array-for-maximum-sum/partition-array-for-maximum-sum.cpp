class Solution {
    int solve(int idx , vector<int>&arr , int k , int maxi){
        int n = arr.size();
        if(idx>=n){
            return 0;
        }
        int ans = 0;
      
        for(int i=idx;i<=min(idx+k-1,n-1);i++){
               maxi = max(maxi , arr[i]);
               int temp = maxi*(i-idx+1);
               temp += solve(i+1 , arr , k , INT_MIN );
               ans = max(ans , temp);
        }

        return ans;
    }
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {

       // return solve(0, arr, k , INT_MIN);
          int n = arr.size();
          vector<int> dp(n+1 , 0);
          for(int idx=n-1;idx>=0;idx--){
             int ans = 0;
             int maxi = INT_MIN;
             for(int i=idx;i<=min(idx+k-1,n-1);i++){
                maxi = max(maxi , arr[i]);
                int temp = maxi*(i-idx+1);
                temp += dp[i+1];    //   solve(i+1 , arr , k , INT_MIN );
                ans = max(ans , temp);
             }
             dp[idx]= ans;
          }
         return dp[0];
    }
};