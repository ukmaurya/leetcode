class Solution {
    private:
    int solve(int i , int  j , vector<int>&nums){
         if(i>j){
            return 0;
         }
         // bursting in backword direction 
         int ans = INT_MIN;
         for(int k = i;k<=j;k++){
             int left  = solve(i , k-1, nums);
             int right = solve(k+1 , j , nums);
             int cost = left+right+nums[i-1]*nums[k]*nums[j+1];
             ans = max(ans , cost );
         }
         return ans;
    }
    
public:
    int maxCoins(vector<int>& nums) {
    /* 
      nums.push_back(1);
      nums.insert(nums.begin() , 1);
       int n = nums.size();
      return solve(1,n-2 , nums); */
       nums.push_back(1);
       nums.insert(nums.begin() , 1);
       int n = nums.size();
       vector<vector<int>>dp(n+1, vector<int>(n+1,0));
       for(int i = n-2;i>=1;i-- ){
        for(int j=1;j<=n-2;j++){
              // bursting in backword direction 
              if(i>j)
                continue;
               int ans = INT_MIN;
             for(int k = i;k<=j;k++){
                
                int cost = dp[i][k-1]+dp[k+1][j]+nums[i-1]*nums[k]*nums[j+1];
                ans = max(ans , (int)cost );
            }
          dp[i][j]= ans;
         }
       }
      
       return dp[1][n-2];
    }
};