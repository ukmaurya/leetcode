class Solution {
     
    
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int start = 0;
        int end = n-1;
        while(start<=end){
             int mid = start+(end-start)/2;
             if(nums[mid]==target)
              return true;
             else if(nums[mid]==nums[start]&& nums[mid]==nums[end]) // contraction of array 
             {
                start= start+1;
                end= end-1;

             } 
            else if(nums[mid]>=nums[start]){ // left part is sorted 
                 if(nums[mid]>=target && nums[start]<=target){
                    end= mid-1;
                 }
                 else{
                    start = mid+1;
                 }

            }
            else{ // right part is sorted 
              
               if(nums[mid]<=target && nums[end]>=target){
                  start = mid+1;
               }
               else{
                end= mid-1;
               }

            } 
        }
        return false;
    }
};