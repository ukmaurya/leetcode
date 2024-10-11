class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+= nums[i];
        }
        if(sum&1)
          return false;
        sum = sum/2;
    //     vector<vector<bool>>dp(n+1, vector<bool>(sum+1,false));
    //     for(int i=0;i<n;i++){
    //         dp[i][0]=true;
    //     }
    //     for(int i=n-1;i>=0;i--){
    //         for(int j=1;j<=sum;j++){
    //             bool take = false;
    //             if(j-nums[i]>=0)
    //                take = dp[i+1][j-nums[i]];
    //             bool nottake = dp[i+1][j];
    //             dp[i][j] = take  || nottake;
    //         }
    //     }

    //    return dp[0][sum];

        
        //    space optimised 
          
           vector<bool>down(sum+1 ,false);
           down[0] = true;
            for(int i=n-1;i>=0;i--){
                vector<bool> up(sum+1 , false);
            for(int j=1;j<=sum;j++){
                bool take = false;
                if(j-nums[i]>=0)
                   take = down[j-nums[i]];
                bool nottake = down[j];
                up[j] = take  || nottake;
             }
             down = up;
           }
          return down[sum];
    }
};