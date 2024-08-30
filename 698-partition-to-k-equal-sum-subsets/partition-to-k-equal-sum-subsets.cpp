class Solution {
    bool solve(int idx , vector<int>&nums , vector<int>&vis ,int sum ,  int count , int k, int target){
        int n = nums.size();
         if(count==k)
            return true;     
        if(sum>target )
            return false;
          
        if(sum==target){
            return solve(0, nums , vis , 0, count+1 , k  , target);
        }
        bool ans = false;
        for(int i=idx;i<n;i++){
            if(!vis[i]){
                vis[i]=1;
                ans = ans || solve(i+1,nums , vis, sum+nums[i], count , k ,target );
                vis[i]=0;
            }
        }
        return ans;
    }
    
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n = nums.size();
        int tot =0;
        for(int i=0;i<n;i++){
            tot+= nums[i];
        }
        if(tot%k != 0){
            return false;
        }
        int target = tot/k;
        vector<int>vis(n,0);
       return solve(0,nums, vis ,0, 0 , k, target  );
        
        
    }
};