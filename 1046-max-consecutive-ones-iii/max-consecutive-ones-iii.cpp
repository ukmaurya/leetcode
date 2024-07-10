class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        // consecutive keyword is giving hint that concept will of substring 
         int n = nums.size();
         int front = 0;
         int end = 0;
         int count = 0;
         int maxi = 0;
         while( end < n ){ // variable size sliding window 
            if(nums[end]==0)
              count++;

            if(count<k){
                maxi = max(maxi , end-front+1);
                end++;
            }
            else if(count==k){
                  maxi = max(maxi , end-front+1);
                  end++;
            }  
            else if(count>k){
                while(count > k){
                    if(nums[front]==0)
                      count--;
                   
                    front++;
                    
                }
                end++;

            }
             
         }
         return maxi ;
    }
};