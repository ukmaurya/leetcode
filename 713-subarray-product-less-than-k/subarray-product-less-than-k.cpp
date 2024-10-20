class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k==0)
         return 0;
         int n = nums.size();
         int i=0;
         int j=0;
         int ans = 0;
         long long  prod = 1;
         while(j<n){
             prod = prod*nums[j];
             if(prod < k){
                ans += (j-i+1);
                j++;
             }
             else{
                while(i <= j && prod>=k){
                    prod = prod/nums[i];
                    i++;
                 }
                 if(prod<k)
                   ans+= j-i+1;
                 j++;
             }
         }
         return ans;

    }
        
};