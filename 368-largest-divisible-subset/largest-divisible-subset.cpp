class Solution {
    
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        
       // tabulation
       int n = nums.size(); 
       if(n==1)
         return {nums[0]};
       
       sort(nums.begin() ,nums.end()); // since array , if subsequence asked then we cannot sort
        
       vector<int> ldsSize(n,1); // initially one since every element is divisible by itself 
       vector<int> prev(n,-1);
       int last = -1;
       int maxi = INT_MIN;

       for(int i=0;i<n;i++){
        for(int j=i-1;j>=0;j--){
            if(nums[i]%nums[j]==0 && ldsSize[i]<ldsSize[j]+1){
                ldsSize[i]= ldsSize[j]+1;
                prev[i] = j;
            }
            if(ldsSize[i]>maxi){
                maxi = ldsSize[i];
                last = i;
            }
        }
       }
       vector<int> ans;
       while(last!= -1){
            ans.push_back(nums[last]);
            last = prev[last]; 
       }
       reverse(ans.begin() , ans.end());
       return ans;

    }
};