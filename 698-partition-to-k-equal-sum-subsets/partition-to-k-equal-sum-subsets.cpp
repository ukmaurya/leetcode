class Solution {
    int n;
    bool solve(int index, int mask , int target , int cur_sum ,vector<int>&nums , int k,vector<vector<int>>&dp){
        
        if(k==0){
            if(mask==(1<<n)-1) // all elements are taken
                return true;
            else return false;
        }
        if(dp[index][mask] != -1)
             return dp[index][mask];
        
        if(cur_sum==target ){
            return solve(0,mask,target , 0,nums,k-1,dp);
        }
        
        // take every choice 
        bool ans = false;
        for(int i = index;i<n;i++){
            if(nums[i]<=(target-cur_sum) && !(mask&(1<<i))){
                int newMask = mask|(1<<i);
                ans = ans || solve(i,newMask,target,nums[i]+cur_sum , nums,k,dp);
            }
            if(ans == true )
                 return dp[index][mask]=true;
            
        }
        return dp[index][mask]=false;
    }
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        
        // bit mask dp but it involves differnet approach 
        
        n = nums.size();
        int target = 0;
        for(int i=0;i<n;i++){
            target += nums[i];
        }
        if(target%k!=0){
            return false;
        }
        target = target/k;
        int mask = 0; // no element i taken
        vector<vector<int>> dp(n,vector<int>((1<<n),-1));
        return solve(0,mask,target,0,nums,k,dp);
        
    }
};