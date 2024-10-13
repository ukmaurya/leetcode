class Solution {
public:
    int maxCoins(vector<int>& nums) {
        nums.push_back(1);
        nums.insert(nums.begin() , 1);
        int n = nums.size();
        vector<vector<int>>dp(n,vector<int>(n,0));
        for(int i=n-2;i>=1;i--){
            for(int j=1;j<=n-2;j++){
                if(i>j)
                  continue;
                int maxi = 0;
                for(int k=i;k<=j;k++){
                   int coin = nums[k]*nums[i-1]*nums[j+1];
                   int last = dp[i][k-1] + dp[k+1][j]+coin;
                   maxi = max(maxi , last);
                }
                dp[i][j] = maxi;

            }
        }
        return dp[1][n-2];
    }
};