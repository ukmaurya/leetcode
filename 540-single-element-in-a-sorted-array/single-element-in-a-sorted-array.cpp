class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        if(n==1)
         return nums[0];
        if(nums[0]!= nums[1])
          return nums[0];
        if(nums[n-1]!= nums[n-2])
           return nums[n-1];  
        int start = 1;
        int end = n-2;
        int ans = -1;
        while(start<= end){
            int mid = ( start+end)/2;
            if(nums[mid]!= nums[mid-1] && nums[mid] != nums[mid+1]){
                ans =  nums[mid];
                break;
            }
           else if(nums[mid] != nums[mid-1] ){ // first accurancce 
                if(mid%2==0){
                   
                    start = mid+1;
                }
                else{
                    end = mid-1;
                }
               
            }
            else{ // second accurance 
                 if(mid%2==0){
                    end = mid-1;
                 }
                 else{
                    start = mid+1;
                 }

            }
            
        }
        return ans;
    }
};