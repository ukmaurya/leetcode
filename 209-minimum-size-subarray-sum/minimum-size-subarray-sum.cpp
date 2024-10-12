class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
             int i=0;
             int j=0;
             int n = nums.size();
             int ans = INT_MAX;
             int sum=0;
             while(j<n){
                  sum+= nums[j];
                  if(sum<target){
                    j++;
                  }
                  else{
                    while(sum>=target){
                          if(sum>=target){
                             ans = min(ans , j-i+1);
                          }
                         sum -= nums[i];
                         i++;
                    }
                    
                    j++;
                  }
             }
          if(ans == INT_MAX)
            return 0;
          return ans;
    }
};