class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
    
         int n = nums.size();
         int i=0;
         int j=0;
        long long ans = 0;
         long long sum = 0;
         while(j<n){
             sum += nums[j];
             long long score = sum*(j-i+1);
             if(score < k){
                ans += (j-i+1);
                j++;
             }
             else{
                while(i <= j && score>=k){
                    sum = sum-nums[i];
                    i++;
                    score = sum*(j-i+1);
                 }
                 if(score<k)
                   ans+= j-i+1;
                 j++;
             }
         }
         return ans;

    }
};