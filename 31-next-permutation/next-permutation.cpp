class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int index = -1;
        for(int i=n-1;i>0;i--){
            if(nums[i]>nums[i-1]){
                index = i;
                break;
            }
        }
        if(index == -1){ // num is in increasing order
            reverse(nums.begin() , nums.end());
            return;
        }
        reverse(nums.begin()+index , nums.end());
        // find index of just greater element that left 
        int idx = index;
        for(int i=idx;i<n;i++){  // since it will be in increasing order
               if(nums[i]>nums[index-1]){
                idx = i;
                break;
               }
             
        }
        swap(nums[idx] , nums[index-1]);
        return;
    }
};