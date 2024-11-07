class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int start = 0;
        int end = n-1;
        int ans = -1;
        while(start<= end){
            int mid = (start+end)/2;
            if(nums[mid]== target){
                ans = mid;
                break;
            }
            // try to find which half is sorted , then only we can take to decision of movement 
            else if(nums[start]<=nums[mid]){ // left part of mid is sorted
                    if(nums[start]<= target && nums[mid]>=target){ // element may present in left part 
                         end = mid-1;
                    }
                    else start = mid+1;
            }
            else{ // right part of mid is sorted
                    if(nums[end]>= target && nums[mid]<= target){
                        start = mid+1;
                    }
                    else{
                        end = mid-1;
                    }
            }
        }
        return ans;
    }
};