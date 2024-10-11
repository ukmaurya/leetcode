class Solution {
    private:
    int solve(int index , vector<int>&nums, int target , vector<vector<int>>&dp){
        // array may contain 0 so different base case
        if(index==0){
            if(target==0&& nums[0]==0)
              return 2;
            if(nums[0]==target || target==0)
              return 1;
            else return 0;   
        }
        int in =0;
        if(nums[index]<= target){
            in = solve(index-1, nums, target-nums[index] , dp);

        }
        int ex = solve(index-1 , nums , target , dp);
        return in+ex;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
         // variation of subset sum 
         // s1 = sum of positives , s2 = sum of negatives 
         //  s1 - s2 = target 
         // but we cannot work with two subset at a time so reduce it to one subset by s2 = total-s1
        //  int total = 0;
        //  for(int i=0;i<nums.size();i++){
        //     total+=nums[i];
        //  }
        //  int req = (target+total)/2;
        //  int n = nums.size();
        //  if(total<abs(target) || (total+target)&1)
        //    return 0;
        //  vector<vector<int>> dp(n,vector<int>(req+1,-1));
        //  return solve(n-1,nums,req,dp);    

        // second approach
         int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int offset = sum; // offset to handle negative indices

        vector<vector<int>> dp(n, vector<int>(2 * sum + 1, -1)); // size adjusted for negative ans
        return newApproach(nums, target, 0, 0, dp, offset);

    }
     int newApproach(vector<int>& nums, int target, int index, int ans, vector<vector<int>> &dp, int offset) {
        if (index == nums.size()) {
            return ans == target ? 1 : 0;
        }

        if (dp[index][ans + offset] != -1) {
            return dp[index][ans + offset];
        }

        int include = newApproach(nums, target, index + 1, ans + nums[index], dp, offset);
        int exclude =newApproach(nums, target, index + 1, ans - nums[index], dp, offset);

        return dp[index][ans + offset] = include + exclude;
    }

};



