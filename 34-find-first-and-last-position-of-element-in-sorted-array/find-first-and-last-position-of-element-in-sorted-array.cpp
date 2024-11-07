class Solution {
    int solvefirst(vector<int>&nums , int target ){
          int n = nums.size();
          int start = 0;
          int end = n-1;
          int ans = -1;
          while(start<= end){
            int mid =( start+end)/2;
            if(nums[mid]==target){
                    ans = mid;
                    end = mid-1;
            }
            else if(nums[mid] > target){
                   
                    end = mid-1;
            }
            else{
                 start = mid+1;
            }
          }
          return ans;
    }
    int solvesec(vector<int>&nums , int target ){
            int n = nums.size();
          int start = 0;
          int end = n-1;
          int ans = -1;
          while(start<= end){
            int mid =( start+end)/2;
            if(nums[mid]==target){
                    ans = mid;
                      start = mid+1;
            }
            else if(nums[mid] < target){
                   
                    start = mid+1;
            }
            else{
                 end = mid-1;
            }
          }
          return ans;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> ans;
        int first = solvefirst(nums, target);
        int sec = solvesec(nums , target);
        ans.push_back(first);
        ans.push_back(sec);
        return ans;

    }

};