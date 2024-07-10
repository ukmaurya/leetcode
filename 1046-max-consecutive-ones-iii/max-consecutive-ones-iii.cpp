class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        // consecutive is giving hint of substring like concept => sliding window 
        int n = nums.size();
        int i= 0;
        int j =0;
        int count = k;
        int ans = 0;
        while(j<n){
            if(nums[j]==1){
                ans = max(ans, j-i+1);
                j++;
               
            }
            else{
                count--;
                if(count>=0){
                  ans = max(ans, j-i+1);
                }
                else if(count<0){
                    while(count<0){
                        if(nums[i]==0){
                            count++;
                        }
                        i++;
                    }
                 if(count>=0){
                  ans = max(ans, j-i+1);
                  }
                }
                j++;
            }
            
        }
        return ans;
        
    }
};