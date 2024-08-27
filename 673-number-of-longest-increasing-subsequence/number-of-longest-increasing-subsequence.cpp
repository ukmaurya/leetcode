class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
       /* int n = nums.size();
        vector<int> far_lis(n,1);
	   
	   // calculating the farward lis 
        int maxi = 0;
	   for(int i=0;i<n;i++){
	       for(int j=0;j<i;j++){
	           if(nums[i]>nums[j] && 1+far_lis[j]>far_lis[i]){
	               far_lis[i] = 1+far_lis[j];
                  maxi = max(maxi , far_lis[i]);
                   
	           }
	       }
	   }
        
        int ans = 0;
        for(int i=0;i<n;i++){
            if(far_lis[i]==maxi)
                ans++;
        }
        return ans; */
        
        // above solution fails on [1,3,5,4,7]
        // as tabulation gives only the LIS fails to tell the number of LIS 
        // it can be avoided using onother vector ie ways by which LIS at a index 
        int n = nums.size();
	   // using tabulation algorithm 
	   vector<int> far_lis(n,1);
	   vector<int> ways(n,1);
	   
	   // calculating the farward lis 
	   for(int i=0;i<n;i++){
	       for(int j=0;j<i;j++){
	           if(nums[i]>nums[j] && 1+far_lis[j]>far_lis[i]){
	               far_lis[i] = 1+far_lis[j];
                   ways[i] = ways[j];
	           }
               else if(nums[i]>nums[j] && 1+far_lis[j]==far_lis[i]){
                   
                   ways[i] = ways[i]+ways[j];
               }
	       }
	   }
       int count=0;
       int long_lis =INT_MIN;
       for(int i=0;i<n;i++){
           long_lis = max(long_lis , far_lis[i]);
       }
       for(int i=0;i<n;i++){
           if(long_lis == far_lis[i]) 
            count+= ways[i];
       }
       return count;
    }
};