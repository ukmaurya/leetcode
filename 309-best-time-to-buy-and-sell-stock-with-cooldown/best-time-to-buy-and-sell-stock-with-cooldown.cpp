class Solution {
    int solve(int idx , int buy , vector<int>&prices){
        int n = prices.size();
        if(idx >= n)
            return 0;
        
        int take = 0;
        if(buy==1){
            take = solve(idx+1,0,prices)-prices[idx];
            
        }
        else{
            take = solve(idx+2,1,prices)+prices[idx];
        }
        int ntake = solve(idx+1,buy,prices);
        return max(take , ntake);
    }
public:
    int maxProfit(vector<int>& prices) {
       // return solve(0,1,prices);
        // int n = prices.size();
        // vector<vector<int>>dp(n+2,vector<int>(3,0));
        // for(int idx=n-1;idx>=0;idx--){
        //     for(int buy=0;buy<=1;buy++){
        //         int take = 0;
        //         if(buy==1){
        //             take = dp[idx+1][0]-prices[idx];
        //         }
        //         else{
        //             take = dp[idx+2][1]+prices[idx];
        //         }
        //         int ntake = dp[idx+1][buy];
        //         dp[idx][buy] = max(take , ntake);
        //     }
        // }
        // return dp[0][1];


         //space optimisation
         int n = prices.size();
         vector<int>down1(3,0);
         vector<int>down2(3,0);
         for(int idx=n-1;idx>=0;idx--){
            vector<int>cur(3,0);
            for(int buy=0;buy<=1;buy++){
                int take = 0;
                if(buy==1){
                    take = down1[0]-prices[idx];
                }
                else{
                    take = down2[1]+prices[idx];
                }
                int ntake = down1[buy];
                cur[buy] = max(take , ntake);
            }
            down2 = down1;
            down1 = cur;

        }

        return down1[1];
    }
};