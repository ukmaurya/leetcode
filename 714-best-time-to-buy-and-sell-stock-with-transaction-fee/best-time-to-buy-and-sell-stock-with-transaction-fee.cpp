class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
         int n = prices.size();
        vector<vector<int>>dp(n+2,vector<int>(3,0));
        for(int idx=n-1;idx>=0;idx--){
            for(int buy=0;buy<=1;buy++){
                int take = 0;
                if(buy==1){
                    take = dp[idx+1][0]-prices[idx];
                }
                else{
                    take = dp[idx+1][1]+prices[idx]-fee;
                }
                int ntake = dp[idx+1][buy];
                dp[idx][buy] = max(take , ntake);
            }
        }
        return dp[0][1];
    }
};